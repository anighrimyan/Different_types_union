#include <iostream> 
#include <string>

bool is_number(std::string& type);
bool is_float(std::string& type);
int from_string_to_int(std::string& type);
float from_string_to_float(std::string& type);

union Types {
	int int_type;
	float float_type;
	char char_type;
	bool bool_type;
	char* string_type = nullptr;
	Types() {
		int_type = 0;
		float_type = 0.0;
		char_type = '\0';
		bool_type = 0;
	};
	~Types() {};
};

int main() {
	Types t[5];
	std::string type{};
	std::cout << "Enter a string for checking a type this value: " << std::endl;
	std::cin >> type;
	std::cout << std::endl;
	if (is_number(type)) {
		std::cout << "The value can be integer, boolean, string or char for int enter i, for boolean enter b, for string enter s, for character enter c:\n" << "ch = ";
		char ch;
		std::cin >> ch;
		std::cout << std::endl;
		if (ch == 'i') {
			t[0].int_type = from_string_to_int(type);
			std::cout << "int = " << t[0].int_type << std::endl;
		}
		else if (ch == 'b' && from_string_to_int(type) != 0) {
			t[3].bool_type = 1;
			std::cout << "bool = " << t[3].bool_type << std::endl;
		}
		else if (ch == 'b' && from_string_to_int(type) == 0) {
			t[3].bool_type = 0;
			std::cout << "bool = " << t[3].bool_type << std::endl;
		}
		else if (ch == 's') {
			char* new_type = new char[type.size() + 1];
			for (int i = 0; i <= type.size(); ++i) {
				new_type[i] = type[i];
			}
			t[4].string_type = new_type;
			std::cout << "string = " << t[4].string_type << std::endl;
			delete[] new_type;
		} 
		else if (ch == 'c' && type.length() == 1) {
			t[2].char_type = type[0];
			std::cout << "char = " << t[2].char_type << std::endl;
		}
		else {
			std::cout << "Wrong charactor." << std::endl;
		}
	}
	else if (is_float(type)) {
		std::cout << "Is float" << std::endl;
		std::cout << "The value can be float or string for float enter f, for string enter s:\n" << "ch = " << std::endl;
		char ch;
		std::cin >> ch;
		std::cout << std::endl;
		if (ch == 'f') {
			t[1].float_type = from_string_to_float(type);
			std::cout << "float = " << t[1].float_type << std::endl;
		}
		else if (ch == 's') {
			char*new_type = new char[type.size() + 1];
			for (int i = 0; i <= type.size(); ++i) {
				new_type[i] = type[i];
			}
			t[4].string_type = new_type;
			std::cout << "string = " << t[4].string_type << std::endl;
			delete[] new_type;
		}
		else {
			std::cout << "Wrong charactor." << std::endl;
		}
	}
	else {
		char* new_type = new char[type.size() + 1];
		for (int i = 0; i <= type.size(); ++i) {
			new_type[i] = type[i];
		}
		t[4].string_type = new_type;
		std::cout << "string = " << t[4].string_type << std::endl;
		delete [] new_type;
	}	
}
 
float from_string_to_float(std::string& type) {
	return std::stof(type);
}

int from_string_to_int(std::string& type) {
	return std::stoi(type);
}

bool is_number(std::string& type) {
	bool result = false;
	for (int i = 0; i < type.size(); ++i) {
		if (type[i] >= '0' && type[i] <= '9') {
			result = true;
		}
		else {
			return false;
		}
	}
	return result;
}

bool is_float(std::string& type) {
	bool result = false;
	int count = 0;
	for (int i = 0; i < type.size() && type[0] != '.' && type[type.size() - 1] != '.'; ++i) {
		if (type[i] == '.') { 
			++count;
		}
	}
	if (count == 1) {
		for (int i = 0; i < type.size(); ++i) {
			if (type[i] >= '0' && type[i] <= '9' || type[i] == '.') {
				result = true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}
	return result;
}