// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "UIFactory.h"
#include "WindowsUIFactory.h"
#include "LinuxUIFactory.h"
#include "MacOSUIFactory.h"
#include "ConsoleApplication1.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    std::cout << "Введите название ОС" << std::endl;
    std::string OS;
    std::cin >> OS;
    UIFactory* factory = nullptr;
    if (OS == "Windows") {
        factory = new WindowsUIFactory();
    }
    else if (OS == "Linux") {
        factory = new LinuxUIFactory();
    }
    else if (OS == "MacOS") {
        factory = new MacOSUIFactory();
    }

    Form* form = factory->createForm();
    Label* label = factory->createLabel();
    TextBox* textBox = factory->createTextBox();
    ComboBox* comboBox = factory->createComboBox();
    Button* button = factory->createButton();

    label->setPosition(100, 100);
    label->setText("Текст");
    textBox->setPosition(200, 100);
    textBox->setText("lorem ipsum");
    std::vector<std::string> items = { "Темная тема", "Светлая тема" };
    comboBox->setItems(items);
    comboBox->setPosition(1820, 1000);
    comboBox->setSelectedIndex(0);
    std::cout << "Выбранная тема: " << comboBox->getItems()[comboBox->getSeletecedIndex()] << std::endl;
    button->setText("OK");
    button->setPosition(150, 150);
    button->Click();
    form->addControl(label);

    delete factory; // освобождаем фабрику после использования

}
