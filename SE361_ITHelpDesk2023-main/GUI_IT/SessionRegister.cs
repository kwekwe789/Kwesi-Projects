using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GUI_IT
{
    public class SessionRegister
    {
        public string Email { get; set; }
        public string FullName { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string UserType { get; set; }
        public string Username { get; set; }
        public string Password { get; set; }
        public SessionRegister()
        {
            Email = string.Empty;
            FullName = string.Empty;
            FirstName = string.Empty;
            LastName = string.Empty;
            UserType = string.Empty;
            Username = string.Empty;
            Password = string.Empty;
        }
    }
}
