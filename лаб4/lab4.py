import time
class keyboardAction:
    def execute(self):
        pass
    
    def undo(self):
        pass

class keyPressAction(keyboardAction):
    def __init__(self, key):
        self.key = key
        
    def execute(self):
        print(f"Нажата клавиша: {self.key}")
        
    def undo(self):
        print(f"Отмена последнего действия: {self.key}")

    def prepareToShow(self):
        return self.key

class comboPressAction(keyboardAction):
    def __init__(self,keys):
        self.keys = keys

    def execute(self):
        print(f"Нажата комбинация: {' + '.join(self.keys)}")

    def undo(self):
        print(f"Отмена последней комбинации: {' + '.join(self.keys)}")

    def prepareToShow(self):
        return ' + '.join(self.keys)

class virtualKeyboard:
    def __init__(self):
        self.history = []
        self.actions = {}

    def pressKey(self, key):
        if key in self.actions.keys():
            self.actions[key].execute()
        else:
            action = keyPressAction(key)
            self.actions[key] = action
            self.actions[key].execute()
        self.history.append(self.actions[key])
        print("Консоль: " + "".join(self.prepareHistory()))

    def pressKombo(self, keys):
        if ' + '.join(keys) in self.actions.keys():
            self.actions[' + '.join(keys)].execute()
        else:
            action = comboPressAction(keys)
            self.actions[' + '.join(keys)] = action
            self.actions[' + '.join(keys)].execute()
        self.history.append(self.actions[' + '.join(keys)])
        print("Консоль: " + "".join(self.prepareHistory()))
            

    def undo(self):
        if len(self.history) != 0:
            action = self.history.pop()
            action.undo()
            print("Консоль: " + "".join(self.prepareHistory()))
        else:
            print("История пуста")
            
    def prepareHistory(self):
        tmp = []
        for element in self.history:
            tmp.append(element.prepareToShow())
        return tmp

    def renameKey(self, oldValue, newValue):
        isExists = False
        for key in self.actions:
            if oldValue == self.actions[key].prepareToShow():
                print("Клавиша " + self.actions[oldValue].prepareToShow(), end="")
                self.actions[oldValue] = keyPressAction(newValue)
                isExists = True
                print(" переназначена на " + self.actions[oldValue].prepareToShow())
        if isExists is False:
            print("Такой клавиши не существует!")

    def renameCombo(self, oldValue, newValue):
        isExists = False
        for key in self.actions:
            if oldValue == self.actions[key].prepareToShow():
                print("Комбинация клавиш " + self.actions[oldValue].prepareToShow(), end="")
                self.actions[oldValue] = comboPressAction(newValue.split(" + "))
                isExists = True
                print(" переназначена на " + self.actions[oldValue].prepareToShow())
        if isExists is False:
            print("Такой комбинации не существует!")
        
class workflow:
    def showWorkflow(keyboard):
        keyboard.undo()
        keyboard.pressKey('Q')
        time.sleep(1)
        keyboard.pressKey('W')
        time.sleep(1)
        keyboard.undo()
        keyboard.pressKombo(['Ctrl', 'A'])
        time.sleep(1)
        keyboard.pressKombo(['Shift', 'Alt'])
        time.sleep(1)
        keyboard.undo()
        keyboard.undo()
        keyboard.undo()
        print("=========================\n")

keyboard = virtualKeyboard()
workflow.showWorkflow(keyboard)
keyboard.renameKey('Q', 'E')
workflow.showWorkflow(keyboard)
keyboard.renameCombo('Ctrl + A', 'Ctrl + D')
workflow.showWorkflow(keyboard)
