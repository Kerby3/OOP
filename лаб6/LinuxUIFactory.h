#pragma once
#include "UIFactory.h"
#include "linuxControls.h"
class LinuxUIFactory : public UIFactory
{
public:
    Form* createForm() override {
        return new LinuxForm();
    }
    Label* createLabel() override {
        return new LinuxLabel();
    }

    TextBox* createTextBox() override {
        return new LinuxTextBox();
    }

    ComboBox* createComboBox() override {
        return new LinuxComboBox();
    }

    Button* createButton() override {
        return new LinuxButton();
    }
};

