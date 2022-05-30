#include <iostream>
#include <fstream>//for filing
#include "string"
using namespace std;

void LogIn();
void signUp();
int bookAnAppointment();
int existingAppointment();
void viewPatients();
bool payFee();

struct logInSystem
{
	string user_Name;
	string password;
	char user_type;
};
struct signUpSystem
{
	char user_type;
	string user_Name;
	string password;
};

struct doctor
{
	string user_name;
	string pwd;
	string name = "doctor mehboob alam";
	int age = 43;
	string speciality = "Neuro surgen";
};
struct patients
{
	string name;
	string userName;
	string password;
	unsigned int phoneNumber;
	char sex;
	unsigned int age;
	string disease;
};

int main()
{
	int choice, userchoice;
	cout << endl
		<< "               Doctor appointment application                 " << endl;
	cout << "--------------------------------------------------------------------" << endl
		<< endl;
	cout << "  1 : signUp " << endl;
	cout << "  2 : Login " << endl;
	cout << "\nEnter a number accordingly : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		signUp();
		break;
	case 2:

		LogIn();

		break;

		cout << "wellcome to the SignUp page" << endl
			<< endl;
		signUp();
		break;
	}

	return 0;
}

void LogIn()
{
	doctor d;
	logInSystem login;
	string user, pass, un, pw, userchoice;
	char user_type;
	int i = 0, userChoice;
	cout << " please press 'd' for doctor 'p' for patient:  ";
	cin >> user_type;
	cout << "Enter your user Name : ";
	cin >> login.user_Name;
	cout << "Enter your password : ";
	cin >> login.password;
	if (user_type == 'd')
	{

		cout << "do you want to see appointments" << endl;
		cout << "if yes then please enter yes: ";
		cin >> userchoice;

		viewPatients();
	}
	else if (user_type = 'p')
	{
		cout << "what do you want " << endl << endl;

		cout << "appointment" << endl;
		cout << "want to see available slots" << endl
			<< endl;
		cout << "3. book an appointment" << endl;
		cout << "4. free slots" << endl;
		cout << "5. doctor's information" << endl;
		cout << "enter a  number accordingly : ";
		cin >> userChoice;
		if (userChoice == 3)
		{
			bookAnAppointment();
		}
		else if (userChoice == 4)
		{
			existingAppointment();
		}
		else if (userChoice == 5)
		{
			cout << "doctors credentials are:" << endl;
			cout << d.name << endl;
			cout << d.speciality << endl;
			cout << d.age << " years old ";
		}
	}

	else
	{
		cout << "please create your account " << endl;
		signUp();
	}

	ifstream accData("patientData.txt", ios::app);
	getline(accData, un);
	getline(accData, pw);
	while (un == login.user_Name && pw == login.password)
	{
		accData;
	}
	accData.close();
}

void signUp()
{
	signUpSystem signup;
	patients p;
	string userWant, un;
	cout << "welcome to the signup page " << endl;
	cout << " please press 'd' for doctor 'p' for patient:  ";
	cin >> signup.user_type;
	if (signup.user_type == 'd')
	{
		cout << "Enter a user name  : ";
		cin >> signup.user_Name;
		cout << "Enter a password : ";
		cin >> signup.password;
	}
	else if (signup.user_type == 'p')
	{
		cout << "Enter a user name  : ";
		cin >> signup.user_Name;
		cout << "Enter a password : ";
		cin >> signup.password;
		cout << "Enter your gender : ";
		cin >> p.sex;
		cout << "enter your age: ";
		cin >> p.age;
		cout << "what is your problem : ";
		cin >> p.disease;
		cout << "enter your phone number: ";
		cin >> p.phoneNumber;
	}
	else if (signup.user_type == 'P')
	{
		cout << "enter your user Name: ";
		cin >> signup.user_Name;
		cout << "enter a password : ";
		cin >> signup.password;
	} if (signup.user_type == 'd')
	{
		ofstream doctor;
		doctor.open("doctorData.txt", ios::app);
		doctor << signup.user_Name << endl;
		doctor << signup.password << endl;
		doctor.close();
	}
	else if (signup.user_type == 'P')
	{
		ofstream PA;
		PA.open("PaData.txt", ios::app);
		PA << signup.user_Name << endl;
		PA << signup.password << endl;
		PA.close();
	}
	else if (signup.user_type == 'p')
	{
		ofstream file;
		file.open("patientData.txt", ios::app);
		file << signup.user_Name << endl;
		file << signup.password << endl;
		file.close();
	}

	cout << endl << endl << "congratulations account created successfully " << endl;
	cout << "want to login" << endl;
	cout << "if you want then please Enter yes : ";
	cin >> userWant;
	if (userWant == "yes")
	{
		LogIn();
	}
}

int bookAnAppointment()
{

	system("cls");

	cout << "\n ----- Book your appointment for particular time slot ---- \n";
	cout << "\n ----- Available slots are---- \n";

	ifstream read;
	read.open("appointment.dat");

	int hoursbook = 10;

	int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int recordFound = 0;

	if (read)
	{
		string line;
		char key = 'A';
		int i = 9;

		while (getline(read, line))
		{
			char temp = line[0];
			int index = (temp);
			arr[index] = 0;
			recordFound = 1;
		}
		if (recordFound == 1)
		{
			cout << "\n Appointment List by Hours:";
			char key = 'A';
			int hours = 9;
			for (int i = 0; i <= 9; i++)
			{
				if (i == 0)
				{
					if (arr[i] == 0)
						cout << "\n " << key << "-> 0" << hours << " - Available";
					else
						cout << "\n " << key << "-> 0" << hours << " - Booked";
				}

				else
				{
					if (arr[i] == 0)
						cout << "\n " << key << "->" << hours << " - Available";
					else
						cout << "\n " << key << "->" << hours << " - Booked";
				}
				hours++;
				key++;
			}
		}

		read.close();
	}
	if (recordFound == 0)
	{
		cout << "\n Appointment Available for following hours :";
		char key = 'A';
		for (int i = 9; i <= 18; i++)
		{
			if (i == 9)
				cout << "\n " << key << " -> 0" << i << " - Available";
			else
				cout << "\n " << key << " -> " << i << " - Booked";
			key++;
		}
	}

	char choice;
	cout << "\n\n Choose your slot: ";
	cin >> choice;

	if (!(choice >= 'A' && choice <= 'Z'))
	{
		cout << "\n Error : Invalid Selection";
		cout << "\n Please selction correct value from menu A- Z";
		cout << "\n Press any key to continue";
		getchar();
		getchar();
		system("cls");
		bookAnAppointment();
	}

	int index = (choice - 65);
	int isBooked = 1;
	if (arr[index] == 0)
		isBooked = 0;

	if (isBooked == 1)
	{
		cout << "\n Error : This Appointment  slot is already booked";
		cout << "\n Please select different slot time !!";
		cout << "\n Press any key to continue!!";
		getchar();
		getchar();
		system("cls");
		bookAnAppointment();
	}

	string name;
	cout << "\n Enter your Name:";
	cin >> name;

	ofstream out;
	out.open("appointment.dat", ios::app);

	if (out)
	{
		int doctorFee, fee;
		cout << choice << ":" << name.c_str() << "\n";
		out.close();
		doctorFee = payFee();
		if (doctorFee)
			cout << "\n Appointment is Successfully Booked for Hours : " << (choice - 65) + 9 << " !!";
		else
		{
			cout << "please pay the full fee " << endl;
			payFee();
		}
	}
	else
	{
		cout << "\n Error while saving booking";
	}

	cout << "\n Please any key to continue..";
	getchar();
	getchar();

	return 0;
}

int existingAppointment()
{
	system("cls");

	cout << "\n ----- List of Available Appointments ---- \n";
	ifstream read;
	read.open("appointment.dat");

	int hoursbook = 10;

	int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int recordFound = 0;

	if (read)
	{
		string line;
		char key = 'A';
		int i = 9;

		while (getline(read, line))
		{
			char temp = line[0];
			int index = (temp - 65);
			arr[index] = 1;
			recordFound = 1;
		}
		if (recordFound == 1)
		{
			cout << "\n Appointment List by hours:";
			char key = 'A';
			int hours = 9;
			for (int i = 0; i <= 9; i++)
			{
				if (i == 0)
				{
					if (arr[i] == 0)
						cout << "\n " << key << "-> 0" << hours << " - Available";
					else
						cout << "\n " << key << "-> 0" << hours << " - Booked";
				}

				else
				{
					if (arr[i] == 0)
						cout << "\n " << key << "->" << hours << " - Available";
					else
						cout << "\n " << key << "->" << hours << " - Booked";
				}
				hours++;
				key++;
			}
		}

		read.close();

		if (recordFound == 0)
		{
			cout << "\n Appointment Available for following hours :";
			char key = 'A';
			for (int i = 9; i <= 18; i++)
			{
				if (i == 9)
					cout << "\n " << key << " -> 0" << i << " - Available";
				else
					cout << "\n " << key << " -> " << i << " - booked";
				key++;
			}
		}
	}
	ofstream out;
	out.open("appointment.dat", ios::app);

	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

void viewPatients()
{
	string drChoice, viewPatient;
	cout << "do you want to see patients appointments please enter viewpatient : ";
	cin >> drChoice;
	ifstream openfile("appointment.dat");
	if (openfile.is_open())
	{
		while (!openfile.eof())
		{
			getline(openfile, viewPatient);
			cout << viewPatient << endl;
		}
	}
}
bool payFee()
{
	int fee;
	cout << "please Enter 1000RS doctor fee: ";
	cin >> fee;
	if (fee == 1000)
		return true;
	return false;
}
