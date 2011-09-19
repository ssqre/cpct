using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using LumiSoft.Media.Wave;
using CpctDotNetDll;

namespace CpctDemo1
{
    public partial class Form1 : Form
    {
        private WaveIn m_SoundIn = null;
        private WaveOut m_SoundOut = null;
        private CpctDotNet cpct = null;
        private bool flag = false;
        private const int BufferSize = 512;
 
        public Form1()
        {
            InitializeComponent();
            m_SoundIn = new WaveIn(WaveIn.Devices[0], 8000, 8, 1, BufferSize);
            m_SoundIn.BufferFull += new BufferFullHandler(SoundBufferFull);
            m_SoundOut = new WaveOut(WaveOut.Devices[0], 8000, 8, 1);
            cpct = new CpctDotNet();
        }

        private void SoundBufferFull(byte[] buffer)
        {
            if (flag==true)
            {
                double se = GetEnergy(buffer);
                if (se > 100)
                {
                    progressBarSE.Value = 100;
                }
                else
                {
                    progressBarSE.Value = (int)se;
                }

                if (se < 2)
                {
                    m_SoundOut.Play(buffer, 0, buffer.Length);
                }
                else
                {
                    int datalength;
                    float[] m_DataIn = Byte2Float(buffer);
                    float[] m_DataOut = new float[BufferSize * 2];
                    cpct.CreateCpctByParams(128, 64, 5);
                    cpct.SetData(m_DataIn, m_DataIn.Length, 1);
                    cpct.SetParams(0, (float)(trackBarPitch.Value / 100.0 * 12.0));
                    cpct.GetData(m_DataOut, out datalength);
                    byte[] m_DataPlay = Float2Byte(m_DataOut);
                    m_SoundOut.Play(m_DataPlay, 0, datalength);
                } 
            }                   
        }

        private void btnGo_Click(object sender, EventArgs e)
        {
            if (flag==true)
            {
                m_SoundIn.Stop();
                flag = false;
                btnGo.Text = "Start";
                progressBarSE.Value = 0;
                trackBarPitch.Value = 0;
            }
            else
            {
                m_SoundIn.Start();
                flag = true;
                btnGo.Text = "Stop";
            }
        }

        private float[] Byte2Float(byte[] buffer)
        {
            float[] temp = new float[buffer.Length];
            for (int i = 0; i < buffer.Length;i++ )
            {
                temp[i] = (float)((buffer[i] - 128.0) / 128.0);
            }
            return temp;
        }

        private byte[] Float2Byte(float[] buffer)
        {
            byte[] temp = new byte[buffer.Length];
            float temp1;
            for (int i = 0; i < buffer.Length;i++ )
            {
                temp1 = buffer[i] * 128 + 128;
                if (temp1>255)
                {
                    temp[i] = 255;
                }
                else if(temp1<0)
                {
                    temp[i] = 0;
                }
                else
                {
                    temp[i] = (byte)temp1;
                }
            }
            return temp;
        }

        private double GetEnergy(byte[] buffer)
        {
            double s = 0;
            for (int i = 0; i < buffer.Length; i++)
            {
                s += Math.Abs(((double)buffer[i] - 128.0) / 255);
            }
            return s;
        }
    }
}
