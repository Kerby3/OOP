#pragma once
#include "Conrols.h"
#include <iostream>

class LinuxForm : public Form {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � LinuxForm" << std::endl;
	}
};

class LinuxLabel : public Label {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � LinuxLabel" << std::endl;
	}
};

class LinuxTextBox : public TextBox {
public:
	void OnValueChanged() override {
		std::cout << "Linux TextBox �������" << std::endl;
		this->setCommand("OnValueChanged");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � LinuxTextBox" << std::endl;
	}
};

class LinuxComboBox : public ComboBox {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � LinuxComboBox" << std::endl;
	}
};

class LinuxButton : public Button {
	void Click() override {
		std::cout << "���� �� LinuxButton" << std::endl;
		this->setCommand("Click");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � LinuxButton" << std::endl;
	}
};

