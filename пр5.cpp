// Обробник натискання кнопки для побудови кривої Без'є
private: System::Void btnDraw_Click(System::Object^ sender, System::EventArgs^ e) {
    Graphics^ g = canvas->CreateGraphics();
    g->Clear(Color::White);

    // Зчитування координат контрольних точок
    float x1 = Convert::ToSingle(tx1->Text), y1 = Convert::ToSingle(ty1->Text);
    float x2 = Convert::ToSingle(tx2->Text), y2 = Convert::ToSingle(ty2->Text);
    float x3 = Convert::ToSingle(tx3->Text), y3 = Convert::ToSingle(ty3->Text);
    float x4 = Convert::ToSingle(tx4->Text), y4 = Convert::ToSingle(ty4->Text);

    Pen^ pCurve = gcnew Pen(Color::Blue, 2.0f);
    float prevX = x1, prevY = y1;

    // Цикл побудови кривої з кроком параметра t від 0 до 1
    for (float t = 0.01f; t <= 1.0f; t += 0.01f) {// Обробник натискання кнопки для побудови кривої Без'є
private: System::Void btnDraw_Click(System::Object^ sender, System::EventArgs^ e) {
    Graphics^ g = canvas->CreateGraphics();
    g->Clear(Color::White);

    // Зчитування координат контрольних точок
    float x1 = Convert::ToSingle(tx1->Text), y1 = Convert::ToSingle(ty1->Text);
    float x2 = Convert::ToSingle(tx2->Text), y2 = Convert::ToSingle(ty2->Text);
    float x3 = Convert::ToSingle(tx3->Text), y3 = Convert::ToSingle(ty3->Text);
    float x4 = Convert::ToSingle(tx4->Text), y4 = Convert::ToSingle(ty4->Text);

    Pen^ pCurve = gcnew Pen(Color::Blue, 2.0f);
    float prevX = x1, prevY = y1;

    // Цикл побудови кривої з кроком параметра t від 0 до 1
    for (float t = 0.01f; t <= 1.0f; t += 0.01f) {
        // Поліноми Бернштейна для кубічної кривої
        float b0 = pow(1.0f - t, 3);
        float b1 = 3.0f * t * pow(1.0f - t, 2);
        float b2 = 3.0f * pow(t, 2) * (1.0f - t);
        float b3 = pow(t, 3);

        // Обчислення поточної координати точки на кривій
        float currX = b0 * x1 + b1 * x2 + b2 * x3 + b3 * x4;
        float currY = b0 * y1 + b1 * y2 + b2 * y3 + b3 * y4;

        g->DrawLine(pCurve, prevX, prevY, currX, currY);
        prevX = currX; prevY = currY;
    }
}
        // Поліноми Бернштейна для кубічної кривої
        float b0 = pow(1.0f - t, 3);
        float b1 = 3.0f * t * pow(1.0f - t, 2);
        float b2 = 3.0f * pow(t, 2) * (1.0f - t);
        float b3 = pow(t, 3);

        // Обчислення поточної координати точки на кривій
        float currX = b0 * x1 + b1 * x2 + b2 * x3 + b3 * x4;
        float currY = b0 * y1 + b1 * y2 + b2 * y3 + b3 * y4;

        g->DrawLine(pCurve, prevX, prevY, currX, currY);
        prevX = currX; prevY = currY;
    }
}
