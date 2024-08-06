using System.Windows.Forms;
using System;
using Microsoft.Data.SqlClient;
using System.Text;
using MailKit.Net.Smtp;
using MailKit;
using MimeKit;
using System.Net.Mail;
using Microsoft.Identity.Client;

namespace GUI_IT
{
    public partial class FrmLogin : Form
    {
        //main form
        private Rectangle buttonRegRect;
        private Rectangle textBoxUsername;
        private Rectangle textBoxPassword;
        private Rectangle LabelDHAA;
        private Rectangle LoginButton;
        private Rectangle PasswordLabel;
        private Rectangle UsernameLabel;
        private Rectangle CheckBoxRemember;
        private Rectangle LinkLabelForgot;
        private Rectangle Picture;
        private Rectangle labelLogin;
        private Rectangle HidePass;
        private Rectangle ShowPass;

        //panel 2
        private Rectangle buttonRegRect2;
        private Rectangle Register;
        private Rectangle FirstNameLabel2;
        private Rectangle LastNameLabel2;
        private Rectangle FirstNameText;
        private Rectangle LastNameText;
        private Rectangle Email2;
        private Rectangle LabelEmail;
        private Rectangle Picture2;
        private Rectangle AHAC;
        private Rectangle Type;
        private Rectangle LabelType;
        private Rectangle LabelRegister;

        //panel 3
        private Rectangle buttonRegRect3;
        private Rectangle RP;
        private Rectangle LabelEmail2;
        private Rectangle Picture3;
        private Rectangle TextEmail2;
        private Rectangle SendVerification;
        private Rectangle Send;

        private Rectangle OriginalFormSize;

        private float originalLabelDHAASize;
        private float originaRegRectangleFSize;
        private float originaltextUsernameFSize;
        private float originaltextPasswordFSize;
        private float originalButtonLoginFSize;
        private float originalLabelPasswordFSize;
        private float originalLabelUsernameFSize;
        private float originalCheckBoxFSize;
        private float originalLinkLabelForgotFSize;
        private float originallabelLoginFSize;


        private SessionRegister regSession;

        private SessionRegister newUser;


        public FrmLogin()
        {
            InitializeComponent();
            newUser = new SessionRegister();
            pnlSignUp.Visible = false;
            pnlForgotPassword.Visible = false;
            lblIncorrectLogin.Visible = false;
            lblInvalidRole.Visible = false;
            lblAlreadyExists.Visible = false;
            btnOpenEye.FlatAppearance.BorderSize = 0;
            btnOpenEye.FlatAppearance.BorderColor = Color.FromArgb(0, 255, 255, 255);
            btnClosedEye.FlatAppearance.BorderSize = 0;
            btnClosedEye.FlatAppearance.BorderColor = Color.FromArgb(0, 255, 255, 255);
        }


        private void lblSignIn_Click(object sender, EventArgs e)
        {

        }

        private void lblRegisterAccount_Click_1(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }


        private void FrmLogin_Load(object sender, EventArgs e)
        {
            OriginalFormSize = new Rectangle(this.Location.X, this.Location.Y, this.Size.Width, this.Size.Height);
            buttonRegRect = new Rectangle(btnRegisterAccount.Location.X, btnRegisterAccount.Location.Y, btnRegisterAccount.Width, btnRegisterAccount.Height);
            textBoxUsername = new Rectangle(txtUsername.Location.X, txtUsername.Location.Y, txtUsername.Width, txtUsername.Height);
            textBoxPassword = new Rectangle(txtPassword.Location.X, txtPassword.Location.Y, txtPassword.Width, txtPassword.Height);
            LabelDHAA = new Rectangle(lblRegisterAccount.Location.X, lblRegisterAccount.Location.Y, lblRegisterAccount.Width, lblRegisterAccount.Height);
            LoginButton = new Rectangle(btnLogin.Location.X, btnLogin.Location.Y, btnLogin.Width, btnLogin.Height);
            PasswordLabel = new Rectangle(lblFirstRegister.Location.X, lblFirstRegister.Location.Y, lblFirstRegister.Width, lblFirstRegister.Height);
            UsernameLabel = new Rectangle(lblUsernameLogin.Location.X, lblUsernameLogin.Location.Y, lblUsernameLogin.Width, lblUsernameLogin.Height);
            //CheckBoxRemember = new Rectangle(checkboxRemember.Location.X, checkboxRemember.Location.Y, checkboxRemember.Width, checkboxRemember.Height);
            LinkLabelForgot = new Rectangle(linklblForgot.Location.X, linklblForgot.Location.Y, linklblForgot.Width, linklblForgot.Height);
            Picture = new Rectangle(pictureBox1.Location.X, pictureBox1.Location.Y, pictureBox1.Width, pictureBox1.Height);
            labelLogin = new Rectangle(lblLogin.Location.X, lblLogin.Location.Y, lblLogin.Width, lblLogin.Height);
            ShowPass = new Rectangle(btnOpenEye.Location.X, btnOpenEye.Location.Y, btnOpenEye.Width, btnOpenEye.Height);
            HidePass = new Rectangle(btnClosedEye.Location.X, btnClosedEye.Location.Y, btnClosedEye.Width, btnClosedEye.Height);

            buttonRegRect2 = new Rectangle(btnLoginForm.Location.X, btnLoginForm.Location.Y, btnLoginForm.Width, btnLoginForm.Height);
            AHAC = new Rectangle(lblSignIn.Location.X, lblSignIn.Location.Y, lblSignIn.Width, lblSignIn.Height);
            Register = new Rectangle(btnRegister.Location.X, btnRegister.Location.Y, btnRegister.Width, btnRegister.Height);
            FirstNameLabel2 = new Rectangle(lblFirstName.Location.X, lblFirstName.Location.Y, lblFirstName.Width, lblFirstName.Height);
            LastNameLabel2 = new Rectangle(lblLastName.Location.X, lblLastName.Location.Y, lblLastName.Width, lblLastName.Height);
            FirstNameText = new Rectangle(txtFirstName.Location.X, txtFirstName.Location.Y, txtFirstName.Width, txtFirstName.Height);
            LastNameText = new Rectangle(txtLastName.Location.X, txtLastName.Location.Y, txtLastName.Width, txtLastName.Height);
            LabelEmail = new Rectangle(lblEmail.Location.X, lblEmail.Location.Y, lblEmail.Width, lblEmail.Height);
            Email2 = new Rectangle(txtEmail.Location.X, txtEmail.Location.Y, txtEmail.Width, txtEmail.Height);
            Type = new Rectangle(cboUserType.Location.X, cboUserType.Location.Y, cboUserType.Width, cboUserType.Height);
            LabelType = new Rectangle(lblUserType.Location.X, lblUserType.Location.Y, lblUserType.Width, lblUserType.Height);
            Picture2 = new Rectangle(pictureBox4.Location.X, pictureBox4.Location.Y, pictureBox4.Width, pictureBox4.Height);
            LabelRegister = new Rectangle(lblRegister.Location.X, lblRegister.Location.Y, lblRegister.Width, lblRegister.Height);

            buttonRegRect3 = new Rectangle(btnBacktoLogin.Location.X, btnBacktoLogin.Location.Y, btnBacktoLogin.Width, btnBacktoLogin.Height);
            RP = new Rectangle(lblRememebr.Location.X, lblRememebr.Location.Y, lblRememebr.Width, lblRememebr.Height);
            LabelEmail2 = new Rectangle(label1.Location.X, label1.Location.Y, label1.Width, label1.Height);
            Picture3 = new Rectangle(pictureBox5.Location.X, pictureBox5.Location.Y, pictureBox5.Width, pictureBox5.Height);
            TextEmail2 = new Rectangle(txtPassReset.Location.X, txtPassReset.Location.Y, txtPassReset.Width, txtPassReset.Height);
            SendVerification = new Rectangle(label2.Location.X, label2.Location.Y, label2.Width, label2.Height);
            Send = new Rectangle(btnPassReset.Location.X, btnPassReset.Location.Y, btnPassReset.Width, btnPassReset.Height);

            originaRegRectangleFSize = btnRegisterAccount.Font.Size;
            originalLabelDHAASize = lblRegisterAccount.Font.Size;
            originaltextUsernameFSize = txtUsername.Font.Size;
            originaltextPasswordFSize = txtPassword.Font.Size;
            originalLabelUsernameFSize = lblUsernameLogin.Font.Size;
            originalLabelPasswordFSize = lblFirstRegister.Font.Size;
            //originalCheckBoxFSize = checkboxRemember.Font.Size;
            originalLinkLabelForgotFSize = linklblForgot.Font.Size;
            originallabelLoginFSize = lblLogin.Font.Size;

        }

        private void resizeControl(Rectangle r, Control c, float originalFontSize)
        {
            float xRatio = (float)(this.Width) / (float)(OriginalFormSize.Width);
            float yRatio = (float)(this.Height) / (float)(OriginalFormSize.Height);

            int newX = (int)(r.Location.X * xRatio);
            int newY = (int)(r.Location.Y * yRatio);

            int newWidth = (int)(r.Width * xRatio);
            int newHeight = (int)(r.Height * yRatio);

            c.Location = new Point(newX, newY);
            c.Size = new Size(newWidth, newHeight);

            /* float ratio = xRatio; 
             if(xRatio>=yRatio)
             {
                 ratio = yRatio;
             }

             float newFontSize = originalFontSize * ratio;

             Font newFont = new Font(Control.DefaultFont.FontFamily, newFontSize);
             Font= newFont;*/
        }


        private void resizecontroltwo(Rectangle r, Control c)
        {
            float xRatio = (float)(this.Width) / (float)(OriginalFormSize.Width);
            float yRatio = (float)(this.Height) / (float)(OriginalFormSize.Height);

            int newX = (int)(r.Location.X * xRatio);
            int newY = (int)(r.Location.Y * yRatio);

            int newWidth = (int)(r.Width * xRatio);
            int newHeight = (int)(r.Height * yRatio);

            c.Location = new Point(newX, newY);
            c.Size = new Size(newWidth, newHeight);
        }


        private void ChangeLoca(Rectangle r, Control c, float originalFontSize)
        {

            float xRatio = (float)(this.Width) / (float)(OriginalFormSize.Width);
            float yRatio = (float)(this.Height) / (float)(OriginalFormSize.Height);

            int newX = (int)(r.Location.X * xRatio);
            int newY = (int)(r.Location.Y * yRatio);

            c.Location = new Point(newX, newY);

        }


        private void FrmLogin_Resize(object sender, EventArgs e)
        {
            resizeControl(buttonRegRect, btnRegisterAccount, originaRegRectangleFSize);
            resizeControl(textBoxUsername, txtUsername, originaltextUsernameFSize);
            resizeControl(textBoxPassword, txtPassword, originaltextPasswordFSize);
            resizeControl(LabelDHAA, lblRegisterAccount, originalLabelDHAASize);
            resizeControl(LoginButton, btnLogin, originalButtonLoginFSize);
            resizeControl(labelLogin, lblLogin, originallabelLoginFSize);
            resizeControl(PasswordLabel, lblFirstRegister, originalLabelPasswordFSize);
            resizeControl(UsernameLabel, lblUsernameLogin, originalLabelUsernameFSize);
            //resizeControl(CheckBoxRemember, checkboxRemember, originalCheckBoxFSize);
            ChangeLoca(LinkLabelForgot, linklblForgot, originalLinkLabelForgotFSize);
            resizeControl(Picture, pictureBox1, originalLabelDHAASize);
            ChangeLoca(HidePass, btnClosedEye, originalLabelDHAASize);
            ChangeLoca(ShowPass, btnOpenEye, originalLabelDHAASize);

            resizecontroltwo(buttonRegRect2, btnLoginForm);
            resizecontroltwo(AHAC, lblSignIn);
            resizecontroltwo(FirstNameLabel2, lblFirstName);
            resizecontroltwo(LastNameLabel2, lblLastName);
            resizecontroltwo(LabelEmail, lblEmail);
            resizecontroltwo(Email2, txtEmail);
            resizecontroltwo(Type, cboUserType);
            resizecontroltwo(LabelType, lblUserType);
            resizecontroltwo(Picture2, pictureBox4);
            resizecontroltwo(Register, btnRegister);
            resizecontroltwo(FirstNameText, txtFirstName);
            resizecontroltwo(LastNameText, txtLastName);
            resizecontroltwo(LabelRegister, lblRegister);

            resizecontroltwo(RP, lblRememebr);
            resizecontroltwo(buttonRegRect3, btnBacktoLogin);
            resizecontroltwo(Picture3, pictureBox5);
            resizecontroltwo(TextEmail2, txtPassReset);
            resizecontroltwo(LabelEmail2, label1);
            resizecontroltwo(Send, btnPassReset);
            resizecontroltwo(SendVerification, label2);
        }


        private void lblAlreadyExists_Click(object sender, EventArgs e)
        {

        }

        private void pnlForgotPassword_Paint(object sender, PaintEventArgs e)
        {

        }


        private void btnBacktoLogin_Click(object sender, EventArgs e)
        {
            pnlSignUp.Visible = false;
            pnlForgotPassword.Visible = false;
            lblIncorrectLogin.Visible = false;
            lblInvalidRole.Visible = false;
            lblAlreadyExists.Visible = false;
            this.Text = "IT Help Desk Login";
            txtUsername.Text = String.Empty;
            txtPassword.Text = String.Empty;
        }

        private void btnLoginForm_Click(object sender, EventArgs e)
        {
            pnlSignUp.Visible = false;
            pnlForgotPassword.Visible = false;
            lblIncorrectLogin.Visible = false;
            lblInvalidRole.Visible = false;
            lblAlreadyExists.Visible = false;
            this.Text = "IT Help Desk Login";
            txtUsername.Text = String.Empty;
            txtPassword.Text = String.Empty;
        }

        private void btnRegister_Click(object sender, EventArgs e)
        {
            Random res1 = new Random();
            String str1 = "0123456789";
            int size1 = 4;
            String randomstring1 = "";
            for (int i = 0; i < size1; i++)
            {
                int x = res1.Next(str1.Length);
                randomstring1 = randomstring1 + str1[x];
            }
            string name = txtFirstName.Text.ToString() + " " + txtLastName.Text.ToString();
            string first = txtFirstName.Text.ToString();
            string last = txtLastName.Text.ToString();
            string email = txtEmail.Text.ToString();
            string role = cboUserType.Text.ToString();
            string user = name[0].ToString() + txtLastName.Text.ToString() + randomstring1.ToString();
            DateTime time = DateTime.Now;
            Boolean accountExists = Sql.Exists(user);
            Boolean validEmail = Email.isValid(email);
            if (accountExists == false && validEmail == true)
            {
                string pass = Sql.GeneratePassword(user);
                Sql.Register(user, name, first, last, pass, email, role, time);
                int kk = 1;
                Email.sendEmail("Registration", user, kk);
                MessageBox.Show("Your account registration has been a success. You will recieve an email update regarding your account status after your credentials have been reviewed by an adminstrator. ", "Account Successfully Registered!", MessageBoxButtons.OK, MessageBoxIcon.Information);

                pnlSignUp.Visible = false;
                //pnlForgotPassword.Visible = false;
            }
            else if (accountExists == true)
            {
                //MessageBox.Show("Account Already Exists!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                lblAlreadyExists.Visible = true;
            }
            else
            {
                MessageBox.Show("Invalid Email!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            newUser.Username = txtUsername.Text.ToString();
            newUser.Password = txtPassword.Text.ToString();
            newUser.Email = Sql.getEmail(newUser.Username);
            newUser.FirstName = Sql.getName(newUser.Username);
            newUser.FullName = Sql.getfullName(newUser.Username);
            int exists = Sql.Login(newUser.Username, newUser.Password);
            if (exists == 0)
            {
                newUser.UserType = Sql.Role(newUser.Username);
                if (newUser.UserType == "Admin")
                {
                    frmAdmin adminLogIn = new frmAdmin(newUser);
                    this.Hide();
                    adminLogIn.ShowDialog();
                    this.Close();
                }
                else if (newUser.UserType == "Project Member")
                {
                    frmProjectMember projectMemberForm = new frmProjectMember(newUser);
                    this.Hide();
                    projectMemberForm.ShowDialog();
                    this.Close();
                }
                else if (newUser.UserType == "IT Support Team")
                {
                    frmITSupport ITSupportForm = new frmITSupport(newUser);
                    this.Hide();
                    ITSupportForm.ShowDialog();
                    this.Close();
                }
                else if (newUser.UserType == "Report Manager")
                {
                    frmReportManage ReportManageForm = new frmReportManage(newUser);
                    this.Hide();
                    ReportManageForm.ShowDialog();
                    this.Close();
                }
                else
                    //MessageBox.Show("Invalid Role! Contact System Administrator!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    lblInvalidRole.Visible = true;

            }
            else
            {
                //MessageBox.Show("Incorrect Login Information", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                lblIncorrectLogin.Visible = true;
            }
        }

        private void linklblForgot_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            pnlForgotPassword.Visible = true;
            pnlSignUp.Visible = false;
            lblIncorrectLogin.Visible = false;
            lblInvalidRole.Visible = false;
            lblAlreadyExists.Visible = false;
            this.Text = "IT Help Desk Forgot Password";
        }

        private void btnOpenEye_Click(object sender, EventArgs e)
        {
            btnOpenEye.Visible = false;
            btnClosedEye.Visible = true;
            txtPassword.UseSystemPasswordChar = true;
        }

        private void btnClosedEye_Click(object sender, EventArgs e)
        {
            btnOpenEye.Visible = true;
            btnClosedEye.Visible = false;
            txtPassword.UseSystemPasswordChar = false;
        }

        private void btnRegisterAccount_Click(object sender, EventArgs e)
        {
            pnlSignUp.Visible = true;
            pnlForgotPassword.Visible = false;
            lblIncorrectLogin.Visible = false;
            lblInvalidRole.Visible = false;
            lblAlreadyExists.Visible = false;
            this.Text = "IT Help Desk Registration";
            txtEmail.Text = String.Empty;
            txtFirstName.Text = String.Empty;
            txtLastName.Text = String.Empty;
        }

        private void lblRegisterAccount_Click(object sender, EventArgs e)
        {

        }

        private void btnPassReset_Click(object sender, EventArgs e)
        {
           bool resetStatus = false;
           resetStatus = Sql.ResetPassword(txtPassReset.Text.ToString());
           if (resetStatus == true)
           {
               MessageBox.Show("Success. Please check the email associated with your account for more details.", "Successful Reset!", MessageBoxButtons.OK, MessageBoxIcon.Information);
           }
           else
           {
               MessageBox.Show("Failure. There was an error when attempting to reset your password. Please check the username entered.", "Failed Reset!", MessageBoxButtons.OK, MessageBoxIcon.Error);
           }
        }
    }
}
