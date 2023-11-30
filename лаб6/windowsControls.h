#pragma once
#include "Conrols.h"
#include <iostream>

class WindowsForm : public Form {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в WindowsForm" << std::endl;
	}
};

class WindowsLabel : public Label {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в WindowsLabel" << std::endl;
	}
};

class WindowsTextBox : public TextBox {
public:
	void OnValueChanged() override {
		std::cout << "Windows TextBox изменен" << std::endl;
		this->setCommand("OnValueChanged");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в WindowsTextBox" << std::endl;
	}
};

class WindowsComboBox : public ComboBox {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в WindowsComboBox" << std::endl;
	}
};

class WindowsButton : public Button {
	void Click() override {
		std::cout << "Клик по Windows Button" << std::endl;
		this->setCommand("Click");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в WindowsButton" << std::endl;
	}
};