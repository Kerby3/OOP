#pragma once
#include "Conrols.h"
#include <iostream>

class LinuxForm : public Form {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в LinuxForm" << std::endl;
	}
};

class LinuxLabel : public Label {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в LinuxLabel" << std::endl;
	}
};

class LinuxTextBox : public TextBox {
public:
	void OnValueChanged() override {
		std::cout << "Linux TextBox изменен" << std::endl;
		this->setCommand("OnValueChanged");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в LinuxTextBox" << std::endl;
	}
};

class LinuxComboBox : public ComboBox {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в LinuxComboBox" << std::endl;
	}
};

class LinuxButton : public Button {
	void Click() override {
		std::cout << "Клик по LinuxButton" << std::endl;
		this->setCommand("Click");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в LinuxButton" << std::endl;
	}
};

