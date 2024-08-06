using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GUI_IT
{
    public partial class frmstatusUpdate : Form
    {
        public frmstatusUpdate()
        {
            InitializeComponent();
            nxtuser();
        }

        private void btnApprove_Click(object sender, EventArgs e)
        {
            string name = Sql.retName();
            string fname = Sql.retFirst();
            string lname = Sql.retLast();
            string email = Sql.retEmail();
            string role = Sql.rerole();
            string user = Sql.retUser();
            string pass = Sql.repass();
            Email.sendEmail("Registration Accepted", user,1);
            Sql.Regis(user, name, fname, lname, pass, email, role);
            Sql.delete(user);
            nxtuser();

        }

        private void btnDeny_Click(object sender, EventArgs e)
        {
            string user = Sql.retUser();
            Email.sendEmail("Registration Denied", user,1);
            Sql.delete(user);
            nxtuser();
        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {


        }

        private void lblfirstName_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void nxtuser()
        {
            string fname = Sql.retFirst();
            txtname.Text = fname;
            string lname = Sql.retLast();
            txtuser.Text = lname;
            string email = Sql.retEmail();
            textemail.Text = email;
            string role = Sql.rerole();
            textrole.Text = role;
           
        }
    }
}
