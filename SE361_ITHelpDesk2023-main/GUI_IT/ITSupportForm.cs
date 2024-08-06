using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.CodeAnalysis;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.Data.SqlClient;
using Microsoft.VisualBasic.ApplicationServices;

namespace GUI_IT
{
    public partial class frmITSupport : Form
    {
        private SessionRegister newUser_;

        public frmITSupport(SessionRegister newUser)
        {
            newUser_ = newUser;
            InitializeComponent();
            lblUser.Text = newUser_.FirstName + "!";
            lblLoggedIn.Text = "Logged in as: " + newUser_.FirstName;
            Fill1();
            Fill2();
            combo();
            combo1();
            combo2();
        }


        private void Fill1()
        {
            string x = newUser_.Username;

            Shared.DataSource = Sql.Sharedd(x);
            //GVS.EditMode = DataGridViewEditMode.EditOnEnter;

        }


        private void combo()
        {
            cbxn.DataSource = Sql.ITname();
            cbxn.DisplayMember = "Name";
        }


        private void Fill2()
        {
            DGVShare.DataSource = Sql.showunsolved(newUser_.Username);
            DGVShare.EditMode = DataGridViewEditMode.EditOnEnter;
        }


        private void combo1()
        {
            cbxid.DataSource = Sql.Sharedd(newUser_.Username);
            cbxid.DisplayMember = "Id";
        }


        private void combo2()
        {
            cbxid2.DataSource = Sql.ticketsSolved(newUser_.Username);
            cbxid2.DisplayMember = "Id";
        }


        private void btnLogout_Click(object sender, EventArgs e)
        {
            FrmLogin LoginScreen = new FrmLogin();
            this.Hide();
            LoginScreen.ShowDialog();
            this.Close();
        }


        private void ProfilePictureBox_Click(object sender, EventArgs e)
        {
            frmUserProf UserProfile = new frmUserProf(newUser_);
            UserProfile.ShowDialog();
        }


        private void btnSolveClear_Click(object sender, EventArgs e)
        {
            
            cbxid.ResetText();
            cbxid.SelectedIndex = -1;
        }


        private void btnSolveTicket_Click(object sender, EventArgs e)
        {
           
        }


        private void btnClear_Click(object sender, EventArgs e)
        {
            txtEmail.Clear();
            cbxid2.ResetText();
            cbxid2.SelectedIndex = -1;
            cbxn.ResetText();
            cbxn.SelectedIndex = -1;
        }


        private void btnShare_Click(object sender, EventArgs e)
        {
            string x = cbxid2.Text.ToString();
            int y = System.Convert.ToInt32(x);
            string a = cbxn.Text.ToString();
            string b = Sql.getUser(a);
            string c = txtEmail.Text.ToString();
            Sql.Addcoll(b, y);
            Sql.add2(b, y, c);
            MessageBox.Show("The ticket you wished to share has now been sent to the user of your choosing.", "Ticket Shared Successfully!", MessageBoxButtons.OK, MessageBoxIcon.Information);

            txtEmail.Clear();
            cbxid2.ResetText();
            cbxid2.SelectedIndex = -1;
            cbxn.ResetText();
            cbxn.SelectedIndex = -1;
            Fill2();
        }


        private void frmITSupport_Load(object sender, EventArgs e)
        {

        }

        private void btnSolveRefresh_Click(object sender, EventArgs e)
        {
            Fill1();

        }

        private void btnShareRefresh_Click(object sender, EventArgs e)
        {
            Fill2();
        }

        private void btnExpandTicket_Click(object sender, EventArgs e)
        {
            try
            {
                string x = cbxid.Text.ToString();
                int tID = System.Convert.ToInt32(x);
                generatedReport frmTickDetails = new generatedReport(tID, 2, newUser_.Username);
                frmTickDetails.ShowDialog();

            }
            catch(System.FormatException ex)
            {
                MessageBox.Show("Please select a ticket!");
            }
        }
    }
}
