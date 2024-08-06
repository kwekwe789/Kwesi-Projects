namespace GUI_IT
{
    partial class frmstatusUpdate
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmstatusUpdate));
            pictureBox3 = new PictureBox();
            pictureBoxIcon = new PictureBox();
            btnApprove = new Button();
            btnDeny = new Button();
            lblStatusQuestion = new Label();
            lblinfo = new Label();
            pictureBox1 = new PictureBox();
            pictureBox4 = new PictureBox();
            pictureBox5 = new PictureBox();
            lblHeader = new Label();
            pictureBox6 = new PictureBox();
            label1 = new Label();
            label2 = new Label();
            lblfirstName = new Label();
            lblUserType = new Label();
            lblEmail = new Label();
            lbllastName = new Label();
            pictureBox7 = new PictureBox();
            pictureBox8 = new PictureBox();
            pictureBox9 = new PictureBox();
            pictureBox10 = new PictureBox();
            txtname = new TextBox();
            txtuser = new TextBox();
            textemail = new TextBox();
            textrole = new TextBox();
            ((System.ComponentModel.ISupportInitialize)pictureBox3).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBoxIcon).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox4).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox5).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox6).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox7).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox8).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox9).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox10).BeginInit();
            SuspendLayout();
            // 
            // pictureBox3
            // 
            pictureBox3.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            pictureBox3.BackColor = Color.Black;
            pictureBox3.Location = new Point(-19, 36);
            pictureBox3.Margin = new Padding(2);
            pictureBox3.Name = "pictureBox3";
            pictureBox3.Size = new Size(615, 41);
            pictureBox3.TabIndex = 37;
            pictureBox3.TabStop = false;
            // 
            // pictureBoxIcon
            // 
            pictureBoxIcon.BackColor = Color.Black;
            pictureBoxIcon.Image = Properties.Resources.redAgentsLogo;
            pictureBoxIcon.Location = new Point(8, 41);
            pictureBoxIcon.Margin = new Padding(2);
            pictureBoxIcon.Name = "pictureBoxIcon";
            pictureBoxIcon.Size = new Size(38, 32);
            pictureBoxIcon.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBoxIcon.TabIndex = 38;
            pictureBoxIcon.TabStop = false;
            // 
            // btnApprove
            // 
            btnApprove.BackColor = Color.Green;
            btnApprove.FlatStyle = FlatStyle.Popup;
            btnApprove.Font = new Font("Microsoft YaHei UI", 10F, FontStyle.Bold, GraphicsUnit.Point);
            btnApprove.ForeColor = Color.White;
            btnApprove.Location = new Point(106, 529);
            btnApprove.Margin = new Padding(2);
            btnApprove.Name = "btnApprove";
            btnApprove.Size = new Size(145, 59);
            btnApprove.TabIndex = 39;
            btnApprove.Text = "Approve";
            btnApprove.UseVisualStyleBackColor = false;
            btnApprove.Click += btnApprove_Click;
            // 
            // btnDeny
            // 
            btnDeny.BackColor = Color.FromArgb(192, 0, 0);
            btnDeny.FlatStyle = FlatStyle.Popup;
            btnDeny.Font = new Font("Microsoft YaHei UI", 10F, FontStyle.Bold, GraphicsUnit.Point);
            btnDeny.ForeColor = Color.White;
            btnDeny.Location = new Point(313, 530);
            btnDeny.Margin = new Padding(2);
            btnDeny.Name = "btnDeny";
            btnDeny.Size = new Size(145, 59);
            btnDeny.TabIndex = 40;
            btnDeny.Text = "Deny";
            btnDeny.UseVisualStyleBackColor = false;
            btnDeny.Click += btnDeny_Click;
            // 
            // lblStatusQuestion
            // 
            lblStatusQuestion.AutoSize = true;
            lblStatusQuestion.Font = new Font("Microsoft YaHei UI", 10F, FontStyle.Regular, GraphicsUnit.Point);
            lblStatusQuestion.Location = new Point(62, 474);
            lblStatusQuestion.Margin = new Padding(2, 0, 2, 0);
            lblStatusQuestion.Name = "lblStatusQuestion";
            lblStatusQuestion.Size = new Size(449, 27);
            lblStatusQuestion.TabIndex = 41;
            lblStatusQuestion.Text = "Approve or Deny the registration of this user?";
            // 
            // lblinfo
            // 
            lblinfo.AutoSize = true;
            lblinfo.Font = new Font("Microsoft YaHei UI", 8F, FontStyle.Bold, GraphicsUnit.Point);
            lblinfo.Location = new Point(31, 95);
            lblinfo.Margin = new Padding(2, 0, 2, 0);
            lblinfo.MaximumSize = new Size(536, 24);
            lblinfo.MinimumSize = new Size(536, 24);
            lblinfo.Name = "lblinfo";
            lblinfo.Size = new Size(536, 24);
            lblinfo.TabIndex = 42;
            lblinfo.Text = "Below is the information of a new user who wishes to register.";
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = Color.Black;
            pictureBox1.Location = new Point(12, 129);
            pictureBox1.Margin = new Padding(2);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(556, 326);
            pictureBox1.TabIndex = 43;
            pictureBox1.TabStop = false;
            // 
            // pictureBox4
            // 
            pictureBox4.BackColor = Color.FromArgb(64, 0, 0);
            pictureBox4.Location = new Point(22, 148);
            pictureBox4.Margin = new Padding(2);
            pictureBox4.Name = "pictureBox4";
            pictureBox4.Size = new Size(536, 289);
            pictureBox4.TabIndex = 44;
            pictureBox4.TabStop = false;
            // 
            // pictureBox5
            // 
            pictureBox5.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            pictureBox5.BackColor = Color.FromArgb(64, 0, 0);
            pictureBox5.Location = new Point(-19, -9);
            pictureBox5.Margin = new Padding(2);
            pictureBox5.Name = "pictureBox5";
            pictureBox5.Size = new Size(623, 46);
            pictureBox5.TabIndex = 45;
            pictureBox5.TabStop = false;
            // 
            // lblHeader
            // 
            lblHeader.AutoSize = true;
            lblHeader.BackColor = Color.FromArgb(64, 0, 0);
            lblHeader.Font = new Font("Microsoft Sans Serif", 11F, FontStyle.Bold, GraphicsUnit.Point);
            lblHeader.ForeColor = Color.White;
            lblHeader.Location = new Point(5, 5);
            lblHeader.Margin = new Padding(2, 0, 2, 0);
            lblHeader.Name = "lblHeader";
            lblHeader.Size = new Size(280, 26);
            lblHeader.TabIndex = 49;
            lblHeader.Text = "Red Agents IT Help Desk";
            // 
            // pictureBox6
            // 
            pictureBox6.BackColor = Color.Black;
            pictureBox6.Location = new Point(39, 514);
            pictureBox6.Margin = new Padding(2);
            pictureBox6.Name = "pictureBox6";
            pictureBox6.Size = new Size(494, 92);
            pictureBox6.TabIndex = 50;
            pictureBox6.TabStop = false;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Microsoft YaHei UI", 10F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ForeColor = Color.Green;
            label1.Location = new Point(62, 474);
            label1.Margin = new Padding(2, 0, 2, 0);
            label1.Name = "label1";
            label1.Size = new Size(95, 27);
            label1.TabIndex = 51;
            label1.Text = "Approve";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Microsoft YaHei UI", 10F, FontStyle.Regular, GraphicsUnit.Point);
            label2.ForeColor = Color.Red;
            label2.Location = new Point(179, 474);
            label2.Margin = new Padding(2, 0, 2, 0);
            label2.Name = "label2";
            label2.Size = new Size(61, 27);
            label2.TabIndex = 52;
            label2.Text = "Deny";
            // 
            // lblfirstName
            // 
            lblfirstName.AutoSize = true;
            lblfirstName.BackColor = Color.Gainsboro;
            lblfirstName.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            lblfirstName.Location = new Point(44, 176);
            lblfirstName.Margin = new Padding(2, 0, 2, 0);
            lblfirstName.Name = "lblfirstName";
            lblfirstName.Size = new Size(119, 25);
            lblfirstName.TabIndex = 53;
            lblfirstName.Text = "First Name: ";
            lblfirstName.Click += lblfirstName_Click;
            // 
            // lblUserType
            // 
            lblUserType.AutoSize = true;
            lblUserType.BackColor = Color.Gainsboro;
            lblUserType.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            lblUserType.Location = new Point(67, 385);
            lblUserType.Margin = new Padding(2, 0, 2, 0);
            lblUserType.Name = "lblUserType";
            lblUserType.Size = new Size(57, 25);
            lblUserType.TabIndex = 54;
            lblUserType.Text = "Role:";
            // 
            // lblEmail
            // 
            lblEmail.AutoSize = true;
            lblEmail.BackColor = Color.Gainsboro;
            lblEmail.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            lblEmail.Location = new Point(64, 315);
            lblEmail.Margin = new Padding(2, 0, 2, 0);
            lblEmail.Name = "lblEmail";
            lblEmail.Size = new Size(65, 25);
            lblEmail.TabIndex = 55;
            lblEmail.Text = "Email:";
            // 
            // lbllastName
            // 
            lbllastName.AutoSize = true;
            lbllastName.BackColor = Color.Gainsboro;
            lbllastName.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            lbllastName.Location = new Point(45, 242);
            lbllastName.Margin = new Padding(2, 0, 2, 0);
            lbllastName.Name = "lbllastName";
            lbllastName.Size = new Size(116, 25);
            lbllastName.TabIndex = 56;
            lbllastName.Text = "Last Name: ";
            // 
            // pictureBox7
            // 
            pictureBox7.BackColor = Color.Gainsboro;
            pictureBox7.Location = new Point(39, 164);
            pictureBox7.Margin = new Padding(2);
            pictureBox7.Name = "pictureBox7";
            pictureBox7.Size = new Size(494, 48);
            pictureBox7.TabIndex = 57;
            pictureBox7.TabStop = false;
            pictureBox7.Click += pictureBox7_Click;
            // 
            // pictureBox8
            // 
            pictureBox8.BackColor = Color.Gainsboro;
            pictureBox8.Location = new Point(39, 230);
            pictureBox8.Margin = new Padding(2);
            pictureBox8.Name = "pictureBox8";
            pictureBox8.Size = new Size(494, 48);
            pictureBox8.TabIndex = 58;
            pictureBox8.TabStop = false;
            // 
            // pictureBox9
            // 
            pictureBox9.BackColor = Color.Gainsboro;
            pictureBox9.Location = new Point(39, 372);
            pictureBox9.Margin = new Padding(2);
            pictureBox9.Name = "pictureBox9";
            pictureBox9.Size = new Size(494, 48);
            pictureBox9.TabIndex = 59;
            pictureBox9.TabStop = false;
            // 
            // pictureBox10
            // 
            pictureBox10.BackColor = Color.Gainsboro;
            pictureBox10.Location = new Point(39, 302);
            pictureBox10.Margin = new Padding(2);
            pictureBox10.Name = "pictureBox10";
            pictureBox10.Size = new Size(494, 48);
            pictureBox10.TabIndex = 60;
            pictureBox10.TabStop = false;
            // 
            // txtname
            // 
            txtname.Location = new Point(159, 174);
            txtname.Margin = new Padding(4);
            txtname.Name = "txtname";
            txtname.ReadOnly = true;
            txtname.Size = new Size(352, 31);
            txtname.TabIndex = 61;
            txtname.TextChanged += textBox1_TextChanged;
            // 
            // txtuser
            // 
            txtuser.Location = new Point(159, 239);
            txtuser.Margin = new Padding(4);
            txtuser.Name = "txtuser";
            txtuser.ReadOnly = true;
            txtuser.Size = new Size(352, 31);
            txtuser.TabIndex = 62;
            // 
            // textemail
            // 
            textemail.Location = new Point(159, 311);
            textemail.Margin = new Padding(4);
            textemail.Name = "textemail";
            textemail.ReadOnly = true;
            textemail.Size = new Size(352, 31);
            textemail.TabIndex = 63;
            // 
            // textrole
            // 
            textrole.Location = new Point(159, 381);
            textrole.Margin = new Padding(4);
            textrole.Name = "textrole";
            textrole.ReadOnly = true;
            textrole.Size = new Size(352, 31);
            textrole.TabIndex = 64;
            // 
            // frmstatusUpdate
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.WhiteSmoke;
            BackgroundImageLayout = ImageLayout.None;
            ClientSize = new Size(586, 626);
            Controls.Add(textrole);
            Controls.Add(textemail);
            Controls.Add(txtuser);
            Controls.Add(txtname);
            Controls.Add(lblEmail);
            Controls.Add(lblUserType);
            Controls.Add(lbllastName);
            Controls.Add(pictureBox10);
            Controls.Add(pictureBox9);
            Controls.Add(pictureBox8);
            Controls.Add(lblfirstName);
            Controls.Add(pictureBox7);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(lblHeader);
            Controls.Add(pictureBox5);
            Controls.Add(pictureBox4);
            Controls.Add(pictureBox1);
            Controls.Add(lblinfo);
            Controls.Add(lblStatusQuestion);
            Controls.Add(btnDeny);
            Controls.Add(btnApprove);
            Controls.Add(pictureBoxIcon);
            Controls.Add(pictureBox3);
            Controls.Add(pictureBox6);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            ImeMode = ImeMode.NoControl;
            Margin = new Padding(2);
            MaximizeBox = false;
            MinimizeBox = false;
            Name = "frmstatusUpdate";
            Text = "Red Agents IT Registration Status Update";
            ((System.ComponentModel.ISupportInitialize)pictureBox3).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBoxIcon).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox4).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox5).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox6).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox7).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox8).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox9).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox10).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private PictureBox pictureBox3;
        private PictureBox pictureBoxIcon;
        private Button btnApprove;
        private Button btnDeny;
        private Label lblStatusQuestion;
        private Label lblinfo;
        private PictureBox pictureBox1;
        private PictureBox pictureBox4;
        private PictureBox pictureBox5;
        private Label lblHeader;
        private PictureBox pictureBox6;
        private Label label1;
        private Label label2;
        private Label lblfirstName;
        private Label lblUserType;
        private Label lblEmail;
        private Label lbllastName;
        private PictureBox pictureBox7;
        private PictureBox pictureBox8;
        private PictureBox pictureBox9;
        private PictureBox pictureBox10;
        private TextBox txtname;
        private TextBox txtuser;
        private TextBox textemail;
        private TextBox textrole;
    }
}