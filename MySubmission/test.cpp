// Design a text editor with a cursor that can do the following:

// Add text to where the cursor is.
// Delete text from where the cursor is (simulating the backspace key).
// Move the cursor either left or right.
// When deleting text, only characters to the left of the cursor will be deleted. The cursor will also remain within the actual text and cannot be moved beyond it. More formally, we have that 0 <= cursor.position <= currentText.length always holds.

// Implement the TextEditor class:

// TextEditor() Initializes the object with empty text.
// void addText(string text) Appends text to where the cursor is. The cursor ends to the right of text.
// int deleteText(int k) Deletes k characters to the left of the cursor. Returns the number of characters actually deleted.
// string cursorLeft(int k) Moves the cursor to the left k times. Returns the last min(10, len) characters to the left of the cursor, where len is the number of characters to the left of the cursor.
// string cursorRight(int k) Moves the cursor to the right k times. Returns the last min(10, len) characters to the left of the cursor, where len is the number of characters to the left of the cursor.

class TextEditor {
public:
    TextEditor() {
        //initialize the object with an empty text
        TextEditor *text = new TextEditor();
        text->cursor = 0;
        text->currentText = "";
    }
    
    void addText(string text) {
        //append text to the right of the cursor
        currentText.insert(cursor, text);
        cursor += text.length();
    }
    
    int deleteText(int k) {
        //delete k characters to the left of the cursor
        int deleted = min(k, cursor);
        currentText.erase(cursor - deleted, deleted);
        cursor -= deleted;
        return deleted;
    }
    
    string cursorLeft(int k) {
        //move the cursor to the left k times
        cursor = max(0, cursor - k);
        return currentText.substr(cursor, min(10, currentText.length() - cursor));
    }
    
    string cursorRight(int k) {
        //move the cursor to the right k times
        cursor = min(currentText.length(), cursor + k);
        return currentText.substr(cursor, min(10, currentText.length() - cursor));
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */