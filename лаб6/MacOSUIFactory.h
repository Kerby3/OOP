#pragma once
#include "UIFactory.h"
#include "MacOSControls.h"
class MacOSUIFactory : public UIFactory
{
public:
    Form* createForm() override {
        return new MacOSForm();
    }
    Label* createLabel() override {
        return new MacOSLabel();
    }

    TextBox* createTextBox() override {
        return new MacOSTextBox();
    }

    ComboBox* createComboBox() override {
        return new MacOSComboBox();
    }

    Button* createButton() override {
        return new MacOSButton();
    }
};

