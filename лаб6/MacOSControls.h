#pragma once
#include "Conrols.h"
#include <iostream>

class MacOSForm : public Form {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в MacOSForm" << std::endl;
	}
};

class MacOSLabel : public Label {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в MacOSLabel" << std::endl;
	}
};

class MacOSTextBox : public TextBox {
public:
	void OnValueChanged() override {
		std::cout << "MacOS TextBox изменен" << std::endl;
		this->setCommand("OnValueChanged");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в MacOSTextBox" << std::endl;
	}
};

class MacOSComboBox : public ComboBox {
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в MacOSComboBox" << std::endl;
	}
};

class MacOSButton : public Button {
	void Click() override {
		std::cout << "Клик по MacOSButton" << std::endl;
		this->setCommand("Click");
		logMethodCall(this->getCommand());
	}
	void logMethodCall(const std::string& methodName) override {
		std::cout << "Метод " << methodName << " Вызван в MacOSButton" << std::endl;
	}
};
