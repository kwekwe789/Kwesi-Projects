namespace GUI_IT
{
    partial class FrmLogin
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FrmLogin));
            pictureBox1 = new PictureBox();
            pictureBox2 = new PictureBox();
            pictureBox3 = new PictureBox();
            lblHeader = new Label();
            lblLogin = new Label();
            txtUsername = new TextBox();
            txtPassword = new TextBox();
            lblUsernameLogin = new Label();
            lblFirstRegister = new Label();
            btnLogin = new Button();
            linklblForgot = new LinkLabel();
            btnRegisterAccount = new Button();
            lblRegisterAccount = new Label();
            pnlSignUp = new Panel();
            lblAlreadyExists = new Label();
            lblUserType = new Label();
            cboUserType = new ComboBox();
            btnRegister = new Button();
            lblLastName = new Label();
            txtLastName = new TextBox();
            lblSignIn = new Label();
            btnLoginForm = new Button();
            lblFirstName = new Label();
            lblEmail = new Label();
            txtFirstName = new TextBox();
            txtEmail = new TextBox();
            lblRegister = new Label();
            pictureBox4 = new PictureBox();
            pnlForgotPassword = new Panel();
            label2 = new Label();
            lblRememebr = new Label();
            txtPassReset = new TextBox();
            pictureBox5 = new PictureBox();
            btnBacktoLogin = new Button();
            btnPassReset = new Button();
            label1 = new Label();
            btnOpenEye = new Button();
            btnClosedEye = new Button();
            lblIncorrectLogin = new Label();
            lblInvalidRole = new Label();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox2).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox3).BeginInit();
            pnlSignUp.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox4).BeginInit();
            pnlForgotPassword.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox5).BeginInit();
            SuspendLayout();
            // 
            // pictureBox1
            // 
            pictureBox1.Anchor = AnchorStyles.None;
            pictureBox1.BackColor = Color.Transparent;
            pictureBox1.Image = Properties.Resources.redAgentsLogo;
            pictureBox1.InitialImage = (Image)resources.GetObject("pictureBox1.InitialImage");
            pictureBox1.Location = new Point(406, 168);
            pictureBox1.Margin = new Padding(2);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(134, 124);
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox1.TabIndex = 0;
            pictureBox1.TabStop = false;
            // 
            // pictureBox2
            // 
            pictureBox2.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            pictureBox2.BackColor = Color.FromArgb(64, 0, 0);
            pictureBox2.Location = new Point(-2, -1);
            pictureBox2.Margin = new Padding(2);
            pictureBox2.Name = "pictureBox2";
            pictureBox2.Size = new Size(976, 62);
            pictureBox2.TabIndex = 1;
            pictureBox2.TabStop = false;
            // 
            // pictureBox3
            // 
            pictureBox3.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            pictureBox3.BackColor = Color.Black;
            pictureBox3.Location = new Point(-2, 49);
            pictureBox3.Margin = new Padding(2);
            pictureBox3.Name = "pictureBox3";
            pictureBox3.Size = new Size(976, 41);
            pictureBox3.TabIndex = 2;
            pictureBox3.TabStop = false;
            // 
            // lblHeader
            // 
            lblHeader.AutoSize = true;
            lblHeader.BackColor = Color.FromArgb(64, 0, 0);
            lblHeader.Font = new Font("Microsoft Sans Serif", 14F, FontStyle.Bold, GraphicsUnit.Point);
            lblHeader.ForeColor = Color.White;
            lblHeader.Location = new Point(2, 11);
            lblHeader.Margin = new Padding(2, 0, 2, 0);
            lblHeader.Name = "lblHeader";
            lblHeader.Size = new Size(353, 32);
            lblHeader.TabIndex = 3;
            lblHeader.Text = "Red Agents IT Help Desk";
            // 
            // lblLogin
            // 
            lblLogin.Anchor = AnchorStyles.None;
            lblLogin.AutoSize = true;
            lblLogin.Font = new Font("Segoe UI", 14F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            lblLogin.Location = new Point(302, 292);
            lblLogin.Margin = new Padding(2, 0, 2, 0);
            lblLogin.Name = "lblLogin";
            lblLogin.Size = new Size(314, 38);
            lblLogin.TabIndex = 4;
            lblLogin.Text = "Login To Your Account";
            // 
            // txtUsername
            // 
            txtUsername.Anchor = AnchorStyles.None;
            txtUsername.Location = new Point(326, 348);
            txtUsername.Margin = new Padding(2);
            txtUsername.Name = "txtUsername";
            txtUsername.PlaceholderText = "Enter Username";
            txtUsername.Size = new Size(288, 31);
            txtUsername.TabIndex = 5;
            // 
            // txtPassword
            // 
            txtPassword.Anchor = AnchorStyles.None;
            txtPassword.Location = new Point(326, 389);
            txtPassword.Margin = new Padding(2);
            txtPassword.Name = "txtPassword";
            txtPassword.PlaceholderText = "Enter Password";
            txtPassword.Size = new Size(288, 31);
            txtPassword.TabIndex = 7;
            txtPassword.UseSystemPasswordChar = true;
            // 
            // lblUsernameLogin
            // 
            lblUsernameLogin.Anchor = AnchorStyles.None;
            lblUsernameLogin.AutoSize = true;
            lblUsernameLogin.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            lblUsernameLogin.Location = new Point(200, 348);
            lblUsernameLogin.Margin = new Padding(2, 0, 2, 0);
            lblUsernameLogin.Name = "lblUsernameLogin";
            lblUsernameLogin.Size = new Size(121, 32);
            lblUsernameLogin.TabIndex = 8;
            lblUsernameLogin.Text = "Username";
            // 
            // lblFirstRegister
            // 
            lblFirstRegister.Anchor = AnchorStyles.None;
            lblFirstRegister.AutoSize = true;
            lblFirstRegister.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            lblFirstRegister.Location = new Point(210, 388);
            lblFirstRegister.Margin = new Padding(2, 0, 2, 0);
            lblFirstRegister.Name = "lblFirstRegister";
            lblFirstRegister.Size = new Size(111, 32);
            lblFirstRegister.TabIndex = 9;
            lblFirstRegister.Text = "Password";
            // 
            // btnLogin
            // 
            btnLogin.Anchor = AnchorStyles.None;
            btnLogin.BackColor = Color.FromArgb(64, 0, 0);
            btnLogin.FlatStyle = FlatStyle.Flat;
            btnLogin.Font = new Font("Segoe UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            btnLogin.ForeColor = Color.White;
            btnLogin.Location = new Point(388, 430);
            btnLogin.Margin = new Padding(2);
            btnLogin.Name = "btnLogin";
            btnLogin.Size = new Size(166, 56);
            btnLogin.TabIndex = 10;
            btnLogin.Text = "Login";
            btnLogin.UseVisualStyleBackColor = false;
            btnLogin.Click += btnLogin_Click;
            // 
            // linklblForgot
            // 
            linklblForgot.ActiveLinkColor = Color.DarkMagenta;
            linklblForgot.Anchor = AnchorStyles.None;
            linklblForgot.AutoSize = true;
            linklblForgot.Location = new Point(653, 392);
            linklblForgot.Margin = new Padding(2, 0, 2, 0);
            linklblForgot.Name = "linklblForgot";
            linklblForgot.Size = new Size(154, 25);
            linklblForgot.TabIndex = 12;
            linklblForgot.TabStop = true;
            linklblForgot.Text = "Forgot Password?";
            linklblForgot.LinkClicked += linklblForgot_LinkClicked;
            // 
            // btnRegisterAccount
            // 
            btnRegisterAccount.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnRegisterAccount.BackColor = Color.FromArgb(64, 0, 0);
            btnRegisterAccount.FlatStyle = FlatStyle.Popup;
            btnRegisterAccount.Font = new Font("Segoe UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            btnRegisterAccount.ForeColor = Color.White;
            btnRegisterAccount.Location = new Point(801, 94);
            btnRegisterAccount.Margin = new Padding(2);
            btnRegisterAccount.Name = "btnRegisterAccount";
            btnRegisterAccount.Size = new Size(155, 39);
            btnRegisterAccount.TabIndex = 14;
            btnRegisterAccount.Text = "Register Here!";
            btnRegisterAccount.UseVisualStyleBackColor = false;
            btnRegisterAccount.Click += btnRegisterAccount_Click;
            // 
            // lblRegisterAccount
            // 
            lblRegisterAccount.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            lblRegisterAccount.AutoSize = true;
            lblRegisterAccount.Font = new Font("Segoe UI", 8F, FontStyle.Regular, GraphicsUnit.Point);
            lblRegisterAccount.Location = new Point(622, 104);
            lblRegisterAccount.Margin = new Padding(2, 0, 2, 0);
            lblRegisterAccount.Name = "lblRegisterAccount";
            lblRegisterAccount.Size = new Size(177, 21);
            lblRegisterAccount.TabIndex = 15;
            lblRegisterAccount.Text = "Don't Have An Account?";
            lblRegisterAccount.Click += lblRegisterAccount_Click;
            // 
            // pnlSignUp
            // 
            pnlSignUp.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            pnlSignUp.AutoSizeMode = AutoSizeMode.GrowAndShrink;
            pnlSignUp.BackColor = Color.Transparent;
            pnlSignUp.Controls.Add(lblAlreadyExists);
            pnlSignUp.Controls.Add(lblUserType);
            pnlSignUp.Controls.Add(cboUserType);
            pnlSignUp.Controls.Add(btnRegister);
            pnlSignUp.Controls.Add(lblLastName);
            pnlSignUp.Controls.Add(txtLastName);
            pnlSignUp.Controls.Add(lblSignIn);
            pnlSignUp.Controls.Add(btnLoginForm);
            pnlSignUp.Controls.Add(lblFirstName);
            pnlSignUp.Controls.Add(lblEmail);
            pnlSignUp.Controls.Add(txtFirstName);
            pnlSignUp.Controls.Add(txtEmail);
            pnlSignUp.Controls.Add(lblRegister);
            pnlSignUp.Controls.Add(pictureBox4);
            pnlSignUp.Location = new Point(8, 94);
            pnlSignUp.Margin = new Padding(2);
            pnlSignUp.Name = "pnlSignUp";
            pnlSignUp.Size = new Size(950, 543);
            pnlSignUp.TabIndex = 16;
            // 
            // lblAlreadyExists
            // 
            lblAlreadyExists.AutoSize = true;
            lblAlreadyExists.Font = new Font("Segoe UI Semibold", 10F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            lblAlreadyExists.ForeColor = Color.FromArgb(192, 0, 0);
            lblAlreadyExists.Location = new Point(129, 452);
            lblAlreadyExists.Margin = new Padding(2, 0, 2, 0);
            lblAlreadyExists.Name = "lblAlreadyExists";
            lblAlreadyExists.Size = new Size(661, 56);
            lblAlreadyExists.TabIndex = 34;
            lblAlreadyExists.Text = "Account Already Exists: An account with that information already exists. \r\n                Please Try Again or contact a System Administrator.";
            lblAlreadyExists.Visible = false;
            // 
            // lblUserType
            // 
            lblUserType.Anchor = AnchorStyles.None;
            lblUserType.AutoSize = true;
            lblUserType.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            lblUserType.Location = new Point(204, 350);
            lblUserType.Margin = new Padding(2, 0, 2, 0);
            lblUserType.Name = "lblUserType";
            lblUserType.Size = new Size(119, 32);
            lblUserType.TabIndex = 31;
            lblUserType.Text = "User Type";
            // 
            // cboUserType
            // 
            cboUserType.Anchor = AnchorStyles.None;
            cboUserType.DropDownStyle = ComboBoxStyle.DropDownList;
            cboUserType.FormattingEnabled = true;
            cboUserType.Items.AddRange(new object[] { "Admin", "Project Member", "IT Support Team", "Report Manager" });
            cboUserType.Location = new Point(328, 348);
            cboUserType.Margin = new Padding(2);
            cboUserType.Name = "cboUserType";
            cboUserType.Size = new Size(288, 33);
            cboUserType.TabIndex = 30;
            // 
            // btnRegister
            // 
            btnRegister.Anchor = AnchorStyles.None;
            btnRegister.BackColor = Color.FromArgb(64, 0, 0);
            btnRegister.FlatStyle = FlatStyle.Popup;
            btnRegister.Font = new Font("Segoe UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            btnRegister.ForeColor = Color.White;
            btnRegister.Location = new Point(384, 394);
            btnRegister.Margin = new Padding(2);
            btnRegister.Name = "btnRegister";
            btnRegister.Size = new Size(166, 56);
            btnRegister.TabIndex = 29;
            btnRegister.Text = "Register";
            btnRegister.UseVisualStyleBackColor = false;
            btnRegister.Click += btnRegister_Click;
            // 
            // lblLastName
            // 
            lblLastName.Anchor = AnchorStyles.None;
            lblLastName.AutoSize = true;
            lblLastName.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            lblLastName.Location = new Point(194, 269);
            lblLastName.Margin = new Padding(2, 0, 2, 0);
            lblLastName.Name = "lblLastName";
            lblLastName.Size = new Size(126, 32);
            lblLastName.TabIndex = 28;
            lblLastName.Text = "Last Name";
            // 
            // txtLastName
            // 
            txtLastName.Anchor = AnchorStyles.None;
            txtLastName.Location = new Point(328, 270);
            txtLastName.Margin = new Padding(2);
            txtLastName.MaxLength = 45;
            txtLastName.Name = "txtLastName";
            txtLastName.PlaceholderText = "Enter Last Name";
            txtLastName.Size = new Size(288, 31);
            txtLastName.TabIndex = 27;
            // 
            // lblSignIn
            // 
            lblSignIn.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            lblSignIn.AutoSize = true;
            lblSignIn.Font = new Font("Segoe UI", 8F, FontStyle.Regular, GraphicsUnit.Point);
            lblSignIn.Location = new Point(599, 13);
            lblSignIn.Margin = new Padding(2, 0, 2, 0);
            lblSignIn.Name = "lblSignIn";
            lblSignIn.Size = new Size(192, 21);
            lblSignIn.TabIndex = 26;
            lblSignIn.Text = "Already Have An Account?";
            // 
            // btnLoginForm
            // 
            btnLoginForm.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnLoginForm.BackColor = Color.FromArgb(64, 0, 0);
            btnLoginForm.FlatStyle = FlatStyle.Popup;
            btnLoginForm.Font = new Font("Segoe UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            btnLoginForm.ForeColor = Color.White;
            btnLoginForm.Location = new Point(795, 2);
            btnLoginForm.Margin = new Padding(2);
            btnLoginForm.Name = "btnLoginForm";
            btnLoginForm.Size = new Size(152, 40);
            btnLoginForm.TabIndex = 25;
            btnLoginForm.Text = "Login Here!";
            btnLoginForm.UseVisualStyleBackColor = false;
            btnLoginForm.Click += btnLoginForm_Click;
            // 
            // lblFirstName
            // 
            lblFirstName.Anchor = AnchorStyles.None;
            lblFirstName.AutoSize = true;
            lblFirstName.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            lblFirstName.Location = new Point(191, 230);
            lblFirstName.Margin = new Padding(2, 0, 2, 0);
            lblFirstName.Name = "lblFirstName";
            lblFirstName.Size = new Size(129, 32);
            lblFirstName.TabIndex = 21;
            lblFirstName.Text = "First Name";
            // 
            // lblEmail
            // 
            lblEmail.Anchor = AnchorStyles.None;
            lblEmail.AutoSize = true;
            lblEmail.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            lblEmail.Location = new Point(251, 310);
            lblEmail.Margin = new Padding(2, 0, 2, 0);
            lblEmail.Name = "lblEmail";
            lblEmail.Size = new Size(71, 32);
            lblEmail.TabIndex = 20;
            lblEmail.Text = "Email";
            // 
            // txtFirstName
            // 
            txtFirstName.Anchor = AnchorStyles.None;
            txtFirstName.Location = new Point(328, 230);
            txtFirstName.Margin = new Padding(2);
            txtFirstName.MaxLength = 45;
            txtFirstName.Name = "txtFirstName";
            txtFirstName.PlaceholderText = "Enter First Name";
            txtFirstName.Size = new Size(288, 31);
            txtFirstName.TabIndex = 19;
            // 
            // txtEmail
            // 
            txtEmail.Anchor = AnchorStyles.None;
            txtEmail.Location = new Point(328, 309);
            txtEmail.Margin = new Padding(2);
            txtEmail.Name = "txtEmail";
            txtEmail.PlaceholderText = "Enter Email";
            txtEmail.Size = new Size(288, 31);
            txtEmail.TabIndex = 18;
            // 
            // lblRegister
            // 
            lblRegister.Anchor = AnchorStyles.None;
            lblRegister.AutoSize = true;
            lblRegister.Font = new Font("Segoe UI", 14F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            lblRegister.Location = new Point(274, 180);
            lblRegister.Margin = new Padding(2, 0, 2, 0);
            lblRegister.Name = "lblRegister";
            lblRegister.Size = new Size(359, 38);
            lblRegister.TabIndex = 17;
            lblRegister.Text = "Register For Your Account";
            // 
            // pictureBox4
            // 
            pictureBox4.Anchor = AnchorStyles.None;
            pictureBox4.BackColor = Color.Transparent;
            pictureBox4.Image = Properties.Resources.redAgentsLogo;
            pictureBox4.InitialImage = (Image)resources.GetObject("pictureBox4.InitialImage");
            pictureBox4.Location = new Point(402, 56);
            pictureBox4.Margin = new Padding(2);
            pictureBox4.Name = "pictureBox4";
            pictureBox4.Size = new Size(134, 124);
            pictureBox4.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox4.TabIndex = 16;
            pictureBox4.TabStop = false;
            // 
            // pnlForgotPassword
            // 
            pnlForgotPassword.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            pnlForgotPassword.AutoSize = true;
            pnlForgotPassword.Controls.Add(label2);
            pnlForgotPassword.Controls.Add(lblRememebr);
            pnlForgotPassword.Controls.Add(txtPassReset);
            pnlForgotPassword.Controls.Add(pictureBox5);
            pnlForgotPassword.Controls.Add(btnBacktoLogin);
            pnlForgotPassword.Controls.Add(btnPassReset);
            pnlForgotPassword.Controls.Add(label1);
            pnlForgotPassword.Location = new Point(8, 94);
            pnlForgotPassword.Name = "pnlForgotPassword";
            pnlForgotPassword.Size = new Size(950, 542);
            pnlForgotPassword.TabIndex = 12;
            pnlForgotPassword.Paint += pnlForgotPassword_Paint;
            // 
            // label2
            // 
            label2.Anchor = AnchorStyles.None;
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label2.Location = new Point(345, 227);
            label2.Name = "label2";
            label2.Size = new Size(249, 38);
            label2.TabIndex = 6;
            label2.Text = "Forgot Password?";
            // 
            // lblRememebr
            // 
            lblRememebr.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            lblRememebr.AutoSize = true;
            lblRememebr.Font = new Font("Segoe UI", 8F, FontStyle.Regular, GraphicsUnit.Point);
            lblRememebr.Location = new Point(623, 10);
            lblRememebr.Name = "lblRememebr";
            lblRememebr.Size = new Size(164, 21);
            lblRememebr.TabIndex = 5;
            lblRememebr.Text = "Remember Password?";
            // 
            // txtPassReset
            // 
            txtPassReset.Anchor = AnchorStyles.None;
            txtPassReset.Location = new Point(337, 275);
            txtPassReset.Name = "txtPassReset";
            txtPassReset.PlaceholderText = "Enter Username";
            txtPassReset.Size = new Size(266, 31);
            txtPassReset.TabIndex = 4;
            // 
            // pictureBox5
            // 
            pictureBox5.Anchor = AnchorStyles.None;
            pictureBox5.BackgroundImage = Properties.Resources.redAgentsLogo;
            pictureBox5.BackgroundImageLayout = ImageLayout.Stretch;
            pictureBox5.Location = new Point(418, 117);
            pictureBox5.Name = "pictureBox5";
            pictureBox5.Size = new Size(111, 106);
            pictureBox5.TabIndex = 3;
            pictureBox5.TabStop = false;
            // 
            // btnBacktoLogin
            // 
            btnBacktoLogin.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnBacktoLogin.AutoSize = true;
            btnBacktoLogin.BackColor = Color.FromArgb(64, 0, 0);
            btnBacktoLogin.FlatStyle = FlatStyle.Popup;
            btnBacktoLogin.Font = new Font("Segoe UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            btnBacktoLogin.ForeColor = Color.White;
            btnBacktoLogin.Location = new Point(794, -2);
            btnBacktoLogin.Margin = new Padding(4);
            btnBacktoLogin.Name = "btnBacktoLogin";
            btnBacktoLogin.Size = new Size(156, 44);
            btnBacktoLogin.TabIndex = 2;
            btnBacktoLogin.Text = "Login Here!";
            btnBacktoLogin.UseVisualStyleBackColor = false;
            btnBacktoLogin.Click += btnBacktoLogin_Click;
            // 
            // btnPassReset
            // 
            btnPassReset.Anchor = AnchorStyles.None;
            btnPassReset.AutoSize = true;
            btnPassReset.BackColor = Color.FromArgb(64, 0, 0);
            btnPassReset.FlatStyle = FlatStyle.Popup;
            btnPassReset.Font = new Font("Segoe UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            btnPassReset.ForeColor = Color.White;
            btnPassReset.Location = new Point(389, 323);
            btnPassReset.Name = "btnPassReset";
            btnPassReset.Size = new Size(167, 49);
            btnPassReset.TabIndex = 1;
            btnPassReset.Text = "Reset Password";
            btnPassReset.UseVisualStyleBackColor = false;
            btnPassReset.Click += btnPassReset_Click;
            // 
            // label1
            // 
            label1.Anchor = AnchorStyles.None;
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(150, 273);
            label1.Name = "label1";
            label1.Size = new Size(183, 32);
            label1.TabIndex = 0;
            label1.Text = "Enter Username";
            // 
            // btnOpenEye
            // 
            btnOpenEye.BackColor = Color.Transparent;
            btnOpenEye.BackgroundImage = Properties.Resources.openEye;
            btnOpenEye.BackgroundImageLayout = ImageLayout.Stretch;
            btnOpenEye.FlatStyle = FlatStyle.Flat;
            btnOpenEye.Location = new Point(618, 390);
            btnOpenEye.Margin = new Padding(2);
            btnOpenEye.Name = "btnOpenEye";
            btnOpenEye.Size = new Size(40, 29);
            btnOpenEye.TabIndex = 18;
            btnOpenEye.TabStop = false;
            btnOpenEye.UseVisualStyleBackColor = false;
            btnOpenEye.Click += btnOpenEye_Click;
            // 
            // btnClosedEye
            // 
            btnClosedEye.BackColor = Color.White;
            btnClosedEye.BackgroundImage = Properties.Resources.closedEye;
            btnClosedEye.BackgroundImageLayout = ImageLayout.Stretch;
            btnClosedEye.FlatStyle = FlatStyle.Flat;
            btnClosedEye.Location = new Point(618, 390);
            btnClosedEye.Margin = new Padding(2);
            btnClosedEye.Name = "btnClosedEye";
            btnClosedEye.Size = new Size(40, 30);
            btnClosedEye.TabIndex = 19;
            btnClosedEye.TabStop = false;
            btnClosedEye.UseVisualStyleBackColor = false;
            btnClosedEye.Click += btnClosedEye_Click;
            // 
            // lblIncorrectLogin
            // 
            lblIncorrectLogin.AutoSize = true;
            lblIncorrectLogin.Font = new Font("Segoe UI Semibold", 10F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            lblIncorrectLogin.ForeColor = Color.FromArgb(192, 0, 0);
            lblIncorrectLogin.Location = new Point(215, 510);
            lblIncorrectLogin.Margin = new Padding(2, 0, 2, 0);
            lblIncorrectLogin.Name = "lblIncorrectLogin";
            lblIncorrectLogin.Size = new Size(515, 56);
            lblIncorrectLogin.TabIndex = 20;
            lblIncorrectLogin.Text = "Incorrect Login Information: The username or password \r\n            you entered is incorrect, please try again.";
            lblIncorrectLogin.Visible = false;
            // 
            // lblInvalidRole
            // 
            lblInvalidRole.AutoSize = true;
            lblInvalidRole.Font = new Font("Segoe UI Semibold", 10F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            lblInvalidRole.ForeColor = Color.FromArgb(192, 0, 0);
            lblInvalidRole.Location = new Point(232, 511);
            lblInvalidRole.Margin = new Padding(2, 0, 2, 0);
            lblInvalidRole.Name = "lblInvalidRole";
            lblInvalidRole.Size = new Size(465, 28);
            lblInvalidRole.TabIndex = 33;
            lblInvalidRole.Text = "Invalid Role: Please contact System Administrator. ";
            lblInvalidRole.Visible = false;
            // 
            // FrmLogin
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.White;
            ClientSize = new Size(968, 648);
            Controls.Add(pnlForgotPassword);
            Controls.Add(pnlSignUp);
            Controls.Add(lblRegisterAccount);
            Controls.Add(linklblForgot);
            Controls.Add(lblInvalidRole);
            Controls.Add(lblIncorrectLogin);
            Controls.Add(btnClosedEye);
            Controls.Add(btnOpenEye);
            Controls.Add(btnRegisterAccount);
            Controls.Add(btnLogin);
            Controls.Add(lblFirstRegister);
            Controls.Add(lblUsernameLogin);
            Controls.Add(txtPassword);
            Controls.Add(txtUsername);
            Controls.Add(lblLogin);
            Controls.Add(lblHeader);
            Controls.Add(pictureBox3);
            Controls.Add(pictureBox2);
            Controls.Add(pictureBox1);
            Icon = (Icon)resources.GetObject("$this.Icon");
            Margin = new Padding(2);
            Name = "FrmLogin";
            Text = "IT Help Desk Login";
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox2).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox3).EndInit();
            pnlSignUp.ResumeLayout(false);
            pnlSignUp.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox4).EndInit();
            pnlForgotPassword.ResumeLayout(false);
            pnlForgotPassword.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox5).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private PictureBox pictureBox1;
        private PictureBox pictureBox2;
        private PictureBox pictureBox3;
        private Label lblHeader;
        private Label lblLogin;
        private TextBox txtUsername;
        private TextBox txtPassword;
        private Label lblUsernameLogin;
        private Label lblFirstRegister;
        private Button btnLogin;
        private LinkLabel linklblForgot;
        private Button btnRegisterAccount;
        private Label lblRegisterAccount;
        private Panel pnlSignUp;
        private Label lblSignIn;
        private Button btnLoginForm;
        private Label lblFirstName;
        private Label lblEmail;
        private TextBox txtFirstName;
        private TextBox txtEmail;
        private Label lblRegister;
        private PictureBox pictureBox4;
        private TextBox txtLastName;
        private Label lblLastName;
        private Button btnRegister;
        private ComboBox cboUserType;
        private Label lblUserType;
        private Panel pnlForgotPassword;
        private Label lblRememebr;
        private TextBox txtPassReset;
        private PictureBox pictureBox5;
        private Button btnBacktoLogin;
        private Button btnPassReset;
        private Label label1;
        private Label label2;
        private Button btnOpenEye;
        private Button btnClosedEye;
        private Label lblIncorrectLogin;
        private Label lblInvalidRole;
        private Label lblAlreadyExists;
    }
}