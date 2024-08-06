using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.Data.SqlClient;


namespace GUI_IT
{
    public partial class frmReportManage : Form
    {
        private SessionRegister newUser_;

        public frmReportManage(SessionRegister newUser)
        {
            newUser_ = newUser;
            InitializeComponent();
            Fill();
            Fill1();
            combo();
            combo1();
            lblUser.Text = newUser_.FirstName + "!";
            lblLoggedIn.Text = "Logged in as: " + newUser_.FirstName;
        }


        private void Fill()
        {            
            DGVT.DataSource = Sql.ticketsUnsolved();
        }


        private void combo()
        {
            cbxn.DataSource = Sql.ITname();
            cbxn.DisplayMember = "Name";
        }


        private void Fill1()
        {
            DGVAssign.DataSource = Sql.ticketsUnsolved();
            DGVAssign.EditMode = DataGridViewEditMode.EditOnEnter;
        }


        private void Fill2()
        {
            DGVT.DataSource = Sql.ticketssolvedAll();
            DGVAssign.EditMode = DataGridViewEditMode.EditOnEnter;
        }


        private void Fill3()
        {
            DGVT.DataSource = Sql.ticketsRe();
            DGVAssign.EditMode = DataGridViewEditMode.EditOnEnter;
        }


        private void Fill4()
        {
            DGVAssign.DataSource = Sql.ticketsRe();
            DGVAssign.EditMode = DataGridViewEditMode.EditOnEnter;
        }

        private void combo1()
        {
            cbxid.DataSource = Sql.SelectTick();
            cbxid.DisplayMember = "Id";
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


        private void btnClear_Click(object sender, EventArgs e)
        {
            txtEmail.Clear();
            cbxn.ResetText();
            cbxn.SelectedIndex = -1;
            cbxid.ResetText();
            cbxid.SelectedIndex = -1;
        }


        private void btnAssign_Click(object sender, EventArgs e)
        {
            string x = cbxid.Text.ToString();
            int y = System.Convert.ToInt32(x);
            string k = cbxn.Text.ToString();
            string z = Sql.getUser(k);
            string f = txtEmail.Text.ToString();
            Sql.Addcoll(z, y);
            Sql.add2(z, y, f);
            MessageBox.Show("The ticket has been successfully assigned to the designated user.", "Ticket Assigned!", MessageBoxButtons.OK, MessageBoxIcon.Information);

            txtEmail.Clear();
            cbxn.ResetText();
            cbxn.SelectedIndex = -1;
            cbxid.ResetText();
            cbxid.SelectedIndex = -1;
        }


        private void btnUnsolved_Click(object sender, EventArgs e)
        {
            Fill();
        }


        private void btnSolved_Click(object sender, EventArgs e)
        {
            Fill2();
        }


        private void btnViewUnsolvedTable_Click(object sender, EventArgs e)
        {
            Fill1();
        }


        private void btnViewReopenedTable_Click(object sender, EventArgs e)
        {
            Fill4();
        }


        private void btnReOpened_Click(object sender, EventArgs e)
        {
            Fill3();
        }

        private void btnAssignRefresh_Click(object sender, EventArgs e)
        {
            Fill1();
            Fill3();
        }
    }
}
