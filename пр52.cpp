// Рекурсивна функція побудови фракталу
void DrawTree(Graphics^ g, Pen^ p, float x, float y, float sideA, float sideB, float angle, int k) {
    if (k <= 0) return; // База рекурсії

    // Розрахунок координат вершин прямокутника (стовбура/гілки)
    float x2 = x + sideA * cos(angle);
    float y2 = y - sideA * sin(angle);
    float dx = sideB * sin(angle), dy = sideB * cos(angle);
    float x3 = x2 - dx, y3 = y2 - dy;
    float x4 = x - dx, y4 = y - dy;

    // Відображення поточної ланки дерева
    g->DrawLine(p, x, y, x2, y2);
    g->DrawLine(p, x2, y2, x3, y3);
    g->DrawLine(p, x3, y3, x4, y4);
    g->DrawLine(p, x4, y4, x, y);

    // Розрахунок параметрів для наступних гілок
    float nextSide = sideA * (sqrt(2.0f) / 2.0f);

    // Рекурсивні виклики для лівої та правої гілок (кути +45 та -45 градусів)
    DrawTree(g, p, x4, y4, nextSide, nextSide, angle + 0.7853f, k - 1);
    float topX = x4 + nextSide * cos(angle + 0.7853f);
    float topY = y4 - nextSide * sin(angle + 0.7853f);
    DrawTree(g, p, topX, topY, nextSide, nextSide, angle - 0.7853f, k - 1);
}