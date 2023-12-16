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

    def pressKombo(self, keys):
        if ' + '.join(keys) in self.actions.keys():
            self.actions[' + '.join(keys)].execute()
        else:
            action = comboPressAction(keys)
            self.actions[' + '.join(keys)] = action
            self.actions[' + '.join(keys)].execute()
        self.history.append(self.actions[' + '.join(keys)])
            

    def undo(self):
        if self.history:
            action = self.history.pop()
            action.undo()
            
    def showHistory(self):
        tmp = []
        for element in self.history:
            tmp.append(element.prepareToShow())
        print(tmp)

    def renameKey(self, oldValue, newValue):
        isExists = False
        for element in self.history:
            if element.prepareToShow() == oldValue:
                element.key = newValue
                isExists = True
        for key in self.actions:
            if oldValue == self.actions[key].prepareToShow():
                self.actions[oldValue] = keyPressAction(newValue)
                isExists = True
        if isExists is False:
            print("Такой клавиши не существует!")

    def renameCombo(self, oldValue, newValue):
        isExists = False
        for element in self.history:
            if element.prepareToShow() == oldValue:
                element.keys = newValue.split(' + ')
                isExists = True
        for key in self.actions:
            if oldValue == self.actions[key].prepareToShow():
                self.actions[oldValue] = comboPressAction(newValue.split(" + "))
                isExists = True
        if isExists is False:
            print("Такой комбинации не существует!")
        
class workflow:
    def showWorkflow(keyboard):
        keyboard.pressKey('Q')
        time.sleep(1)
        keyboard.pressKey('W')
        time.sleep(1)
        keyboard.pressKombo(['Ctrl', 'A'])
        time.sleep(1)
        keyboard.pressKombo(['Shift', 'Alt'])
        time.sleep(1)
        keyboard.showHistory()
        keyboard.undo()
        keyboard.showHistory()

keyboard = virtualKeyboard()
workflow.showWorkflow(keyboard)
keyboard.renameKey('Q', 'E')
workflow.showWorkflow(keyboard)
keyboard.renameCombo('Ctrl + A', 'Ctrl + D')
workflow.showWorkflow(keyboard)
