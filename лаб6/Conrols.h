#pragma once
#include <string>
#include <iostream>
#include "Control.h"

class Form : public Control {
public:
    void addControl(Control* control) {
        this->controlVec.push_back(*control);
        this->setCommand("addControl");
        logMethodCall(this->getCommand());
    }
    void logMethodCall(const std::string& methodName) override {
        std::cout << "����� " << methodName << " ������ � Form" << std::endl;
    }
    


private:
    std::vector<Control> controlVec;
};

class Label : public Control {
public:
    void setText(std::string text) {
        this->text = text;
        this->setCommand("setText");
        logMethodCall(this->getCommand());
    }
    std::string getText() {
        this->setCommand("getText");
        logMethodCall(this->getCommand());
        return this->text;
    }
    void logMethodCall(const std::string& methodName) override {
        std::cout << "����� " << methodName << " ������ � Label" << std::endl;
    }
private:
    std::string text;
};

class TextBox : public Control {
public:
    void setText(std::string text) {
        if (this->text != text) {
            OnValueChanged();
        }
        this->setCommand("setText");
        logMethodCall(this->getCommand());
        this->text = text;
    }
    std::string getText() {
        this->setCommand("getText");
        logMethodCall(this->getCommand());
        return this->text;
    }
    virtual void OnValueChanged() {
        std::cout << "����� �������" << std::endl;
        this->setCommand("OnValueChanged");
        logMethodCall(this->getCommand());
    }
    void logMethodCall(const std::string& methodName) override {
        std::cout << "����� " << methodName << " ������ � TextBox" << std::endl;
    }
private:
    std::string text;
};

class ComboBox : public Control {
public:
    int getSeletecedIndex() {
        this->setCommand("getSelectedIndex");
        logMethodCall(this->getCommand());
        return this->selectedIndex;
    }
    void setSelectedIndex(int index) {
        this->selectedIndex = index;
        this->setCommand("setSelectedIndex");
        logMethodCall(this->getCommand());
    }
    void setItems(std::vector<std::string> items) {
        this->items = items;
        this->setCommand("setItems");
        logMethodCall(this->getCommand());
    }
    std::vector<std::string> getItems() {
        this->setCommand("getItems");
        logMethodCall(this->getCommand());
        return this->items;
    }
    void logMethodCall(const std::string& methodName) override {
        std::cout << "����� " << methodName << " ������ � ComboBox" << std::endl;
    }
private:
    std::vector<std::string> items;
    int selectedIndex;
};

class Button : public Control {
public:
    void setText(std::string text) {
        this->text = text;
        this->setCommand("setText");
        logMethodCall(this->getCommand());
    }
    std::string getText() {
        this->setCommand("getText");
        logMethodCall(this->getCommand());
        return this->text;
    }
    virtual void Click() = 0;
    void logMethodCall(const std::string& methodName) override {
        std::cout << "����� " << methodName << " ������ � Button" << std::endl;
    }
private:
    std::string text;
};

