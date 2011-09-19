namespace CpctDemo1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.trackBarPitch = new System.Windows.Forms.TrackBar();
            this.label2 = new System.Windows.Forms.Label();
            this.btnGo = new System.Windows.Forms.Button();
            this.progressBarSE = new System.Windows.Forms.ProgressBar();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarPitch)).BeginInit();
            this.SuspendLayout();
            // 
            // trackBarPitch
            // 
            this.trackBarPitch.Location = new System.Drawing.Point(88, 14);
            this.trackBarPitch.Maximum = 100;
            this.trackBarPitch.Minimum = -100;
            this.trackBarPitch.Name = "trackBarPitch";
            this.trackBarPitch.Size = new System.Drawing.Size(183, 45);
            this.trackBarPitch.TabIndex = 0;
            this.trackBarPitch.TickFrequency = 20;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(30, 26);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "Pitch";
            // 
            // btnGo
            // 
            this.btnGo.Location = new System.Drawing.Point(32, 107);
            this.btnGo.Name = "btnGo";
            this.btnGo.Size = new System.Drawing.Size(86, 29);
            this.btnGo.TabIndex = 2;
            this.btnGo.Text = "Start";
            this.btnGo.UseVisualStyleBackColor = true;
            this.btnGo.Click += new System.EventHandler(this.btnGo_Click);
            // 
            // progressBarSE
            // 
            this.progressBarSE.Location = new System.Drawing.Point(88, 62);
            this.progressBarSE.Name = "progressBarSE";
            this.progressBarSE.Size = new System.Drawing.Size(183, 20);
            this.progressBarSE.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(30, 65);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "Volume";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(299, 152);
            this.Controls.Add(this.progressBarSE);
            this.Controls.Add(this.btnGo);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.trackBarPitch);
            this.Name = "Form1";
            this.Text = "CpctDemo1";
            ((System.ComponentModel.ISupportInitialize)(this.trackBarPitch)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TrackBar trackBarPitch;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnGo;
        private System.Windows.Forms.ProgressBar progressBarSE;
        private System.Windows.Forms.Label label1;
    }
}

