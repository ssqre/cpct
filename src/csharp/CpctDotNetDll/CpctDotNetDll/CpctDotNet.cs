using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace CpctDotNetDll
{
    public class CpctDotNet
    {
#region Members
        private IntPtr m_handle = IntPtr.Zero;
#endregion

#region Native C++ API Methods
        private const string DllName = "cpct_dll.dll";

        [DllImport(DllName)]
        private static extern IntPtr createCpctByDefault();

        [DllImport(DllName)]
        private static extern IntPtr createCpctByParams(int winlen, int hoplen, int nit);

        [DllImport(DllName)]
        private static extern void setData(IntPtr h, [MarshalAs(UnmanagedType.LPArray)] float[] data, int datalength, int nChannels);

        [DllImport(DllName)]
        private static extern void setParams(IntPtr h, float tempo, float pitch);

        [DllImport(DllName)]
        private static extern void getData(IntPtr h, [MarshalAs(UnmanagedType.LPArray)] float[] data, out int datalength);

        [DllImport(DllName)]
        private static extern void destroyCpct(IntPtr h);

#endregion

#region C# Wrapper Methods
        /// <summary>
        /// 
        /// </summary>
        public void CreateCpctByDefault()
        {
            m_handle = createCpctByDefault();
        }

        public void CreateCpctByParams(int winlen, int hoplen, int nit)
        {
            m_handle = createCpctByParams(winlen, hoplen, nit);
        }

        public void SetData(float[] data, int datalength, int nChannels)
        {
            setData(m_handle, data, datalength, nChannels);
        }

        public void SetParams(float tempo, float pitch)
        {
            setParams(m_handle, tempo, pitch);
        }

        public void GetData(float[] data, out int datalength)
        {
            getData(m_handle, data, out datalength);
        }

        public void DestroyCpct()
        {
            destroyCpct(m_handle);
        }
#endregion
    }
}
