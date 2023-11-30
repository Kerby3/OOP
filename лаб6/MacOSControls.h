#pragma once
#include "Conrols.h"
#include <iostream>

class MacOSForm : public Form {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � MacOSForm" << std::endl;
	}
};

class MacOSLabel : public Label {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � MacOSLabel" << std::endl;
	}
};

class MacOSTextBox : public TextBox {
public:
	void OnValueChanged() override {
		std::cout << "MacOS TextBox �������" << std::endl;
		this->setCommand("OnValueChanged");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � MacOSTextBox" << std::endl;
	}
};

class MacOSComboBox : public ComboBox {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � MacOSComboBox" << std::endl;
	}
};

class MacOSButton : public Button {
	void Click() override {
		std::cout << "���� �� MacOSButton" << std::endl;
		this->setCommand("Click");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � MacOSButton" << std::endl;
	}
};
