#include "LineNumberArea.h"
LineNumberArea::LineNumberArea(QPlainTextEdit *editor) : QWidget(editor) {
    codeEditor = editor;
}

QSize LineNumberArea::sizeHint() const {
    return QSize(((CodeEditor*)codeEditor)->lineNumberAreaWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
    ((CodeEditor*)codeEditor)->lineNumberAreaPaintEvent(event);
}
