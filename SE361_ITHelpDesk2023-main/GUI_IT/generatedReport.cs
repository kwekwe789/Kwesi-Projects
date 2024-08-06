using Org.BouncyCastle.Asn1.Ocsp;
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
    public partial class generatedReport : Form
    {
        public int id { get; set; }
        public string username { get; set; }
        public generatedReport(int tID, int z, string user)
        {
            InitializeComponent();
            txtID.Text = tID.ToString();
            txtViewID.Text = tID.ToString();
            txtCategory.Text = Sql.getTicketCategory(tID);
            txtViewCategory.Text = Sql.getTicketCategory(tID);
            txtITMem.Text = Sql.getTicketassign(tID);
            txtRaisedUser.Text = Sql.getTicketUser(tID);
            txtViewRaised.Text = Sql.getTicketUser(tID);
            txtStatus.Text = Sql.getTicketStat(tID);
            txtUrgency.Text = Sql.getTicketPriority(tID);
            txtViewUrgency.Text = Sql.getTicketPriority(tID);
            txtSummary.Text = Sql.getTicketDescription(tID);
            txtTicketProblem.Text = Sql.getTicketDescription(tID);
            textBox1.Text = Sql.getColl(tID);
            txtSolution.Text = Sql.solution(tID);
            username = user;
            id = tID;
            if (z == 0)
            {
                txtSolution.Visible = true;
                txtExtra.Visible = false;
                btnsubmit.Visible = false;
                lblExtra.Visible = false;
                lblSolution.Visible = true;
                pnlExpandTicket.Visible = false;
                lblViewHeader.Visible = false;
            }
            else if (z == 1)
            {
                txtSolution.Visible = false;
                txtExtra.Visible = true;
                btnsubmit.Visible = true;
                lblExtra.Visible = true;
                lblSolution.Visible = false;
                pnlExpandTicket.Visible = false;
                lblViewHeader.Visible = false;
            }
            else
            {
                pnlExpandTicket.Visible = true;
                pnlExpandTicket.BringToFront();
                lblViewHeader.Visible = true;
            }
        }

        private void btnsubmit_Click(object sender, EventArgs e)
        {
            string x = txtExtra.Text;
            Sql.addinfo(x, id);
            MessageBox.Show("You have successfully added extra information to this ticket!", "Ticket Successfully Updated!", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void txtUrgency_TextChanged(object sender, EventArgs e)
        {

        }


        private void lblSolution_Click(object sender, EventArgs e)
        {

        }

        private void btnSolveTicket_Click(object sender, EventArgs e)
        {
            string z = Sql.tickuser(id);
            string k = Sql.tickemail(id);
            string j = txtSol.Text.ToString();
            Sql.solve(id, username, z, k, j);
            MessageBox.Show("Your solution for this ticket has been submitted, thank you.", "Ticket Solved Successfully!", MessageBoxButtons.OK, MessageBoxIcon.Information);
            Email.sendEmail("Solved Ticket", username, 0, id);

            txtSol.Clear();
        }

        private void btnSolveClear_Click(object sender, EventArgs e)
        {
            txtSol.Clear();
        }
    }
}
