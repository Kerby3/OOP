#pragma once
#include "Conrols.h"
#include <iostream>

class WindowsForm : public Form {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � WindowsForm" << std::endl;
	}
};

class WindowsLabel : public Label {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � WindowsLabel" << std::endl;
	}
};

class WindowsTextBox : public TextBox {
public:
	void OnValueChanged() override {
		std::cout << "Windows TextBox �������" << std::endl;
		this->setCommand("OnValueChanged");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � WindowsTextBox" << std::endl;
	}
};

class WindowsComboBox : public ComboBox {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � WindowsComboBox" << std::endl;
	}
};

class WindowsButton : public Button {
	void Click() override {
		std::cout << "���� �� Windows Button" << std::endl;
		this->setCommand("Click");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "����� " << methodName << " ������ � WindowsButton" << std::endl;
	}
};