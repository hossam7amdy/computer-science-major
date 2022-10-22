/// The only one instance!
/*
● Your team lead asked to develop a configuration manager component
    ○ This one loads system default values and critical information
    ○ E.g. Some servers IPs, Databases paths (& usernames & passwords)
    ○ E.g. also loads some heavy files and cache for frequent requests
● After you developed it, you noticed that several code parts create a separate object
    ○ But is is actually loading the same things. It also takes 30 minutes to load data from disk!
● Your team lead suggested the following:
    ○ Change the class to allow ONLY one shared instance
■ No way to make 2 different objects in memory
    ○ This way the class forces any user to use the SAME object (the class itself!)
    ○ Change the next code to do such change
 */

#include<iostream>
#include<vector>
using namespace std;

class ConfigurationManger {
private:
	string configuration_path;
	vector<string> servers_ips;
	string aws_service_url;
	// Other heavy data
	bool is_loaded = false;

	// Private constructor! No one can create instances of this time (or even default one)
	ConfigurationManger(string configuration_path) :
			configuration_path(configuration_path) {
	}

	// Our shared instance
	static ConfigurationManger* conf_mgr;

public:

	// Give public method to return the static (shared) instance
	static ConfigurationManger *GetInstance(const std::string& value) {
		// Be careful: initialize once
		if (conf_mgr == nullptr) {
			cout << "Creating a new ConfigurationManger\n";
			conf_mgr = new ConfigurationManger(value);
		}
		return conf_mgr;
	}

	void Load() {
		if (is_loaded)
			return;
		// some heavy load
		cout << "Lazy loading\n";	// what is lazy loading? Google
		servers_ips.push_back("10.20.30.40");
		servers_ips.push_back("10.20.30.41");
		servers_ips.push_back("10.20.30.42");
		aws_service_url = "https://dynamodb.us-west-2.amazonaws.com";	// what is Amazon AWS?
		is_loaded = true;
	}

	string GetAwsServiceUrl() {	// why not const?
		Load();
		return aws_service_url;
	}
	~ConfigurationManger() {
		// Note, you shouldn't try to destroy the conf_mgr here!!!
		// The first object destroy it but others still use it (or will reload)!

		//FreeInstance();	// if you uncommented = infinite loop. WHY? Answer is below very bottom

		// Quote: Don’t create problems to solve a problem
	}
	static void FreeInstance() {
		if (ConfigurationManger::conf_mgr != nullptr) {
			cout << "Free the instance\n";
			delete ConfigurationManger::conf_mgr;
			ConfigurationManger::conf_mgr = nullptr;
		} else
			cout << "The instance freed already\n";
	}
};

ConfigurationManger* ConfigurationManger::conf_mgr = nullptr;

void f1() {
	ConfigurationManger* mgr = ConfigurationManger::GetInstance("/home/moustafa/conf_info.txt");
	cout << mgr->GetAwsServiceUrl() << "\n";
}

void f2() {
	ConfigurationManger* mgr = ConfigurationManger::GetInstance("/home/moustafa/conf_info.txt");
	cout << mgr->GetAwsServiceUrl() << "\n";
}

/*
 - Saying that we need only ONE instance from this class, may trigger what?
 - Static object: Shared object among all instances
 - Now let's create a static instance to be shared
 - But still users can create objects!
 - The trick is to make the class constructor private!
 - This way no one can create objects!
 - But???? OK, give him a function to return your static object

 - You just learned Singleton Design Pattern :)
*/

int main() {
	f1();
	f2();

	// If we forgot to free, it will be memory leak!
	// We need more elegant solutions!
	ConfigurationManger::FreeInstance();
	return 0;
}


// Because destrctor calls destrctor  calls destrctor   to infinity
// How
// Scope of an object ended, so it calls ~ConfigurationManger(), which calls FreeInstance()
// FreeInstance does: delete ConfigurationManger::conf_mgr;  => which is calling the destructor!
// Which repeat the same!
// Hell :)
