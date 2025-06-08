# GrimoireTome
A C++ and Qt desktop application for creating and managing custom magical grimoires.
# GrimoireTome: A Magical Grimoire Application

![Screenshot of GrimoireTome](grimoire-screenshot.png

A C++ and Qt desktop application for creating, managing, and theming custom magical grimoires. This project is a personal portfolio piece built to explore C++ application development, GUI design, third-party APIs, and cloud integration.

---

### Current Features

* **Create Custom Spells & Pages:** Users can create grimoires from scratch, adding pages and detailed spells with names, categories, and descriptions.
* **Persistent Storage:** Grimoires can be saved to and loaded from local `.json` files.
* **Live Moon Phase Data:** The application fetches and displays live, real-world moon phase data from an online API.
* **Dynamic UI:** A fully interactive three-column layout for navigating pages and spells.
* **Custom Theming:** A magical theme using custom fonts, textures, and a QSS stylesheet for a unique look and feel.

---

### Technologies Used

* **Core:** C++ (17)
* **Framework:** Qt 6 (Widgets, Network)
* **Build System:** CMake
* **Libraries:**
    * nlohmann/json (for JSON serialization)
    * Qt Style Sheets (for UI theming)

---

### Project Roadmap (Future Development)

The journey of this grimoire is just beginning! The next major phase will focus on creating a more immersive experience and adding professional cloud features.

-   [ ] **AWS Cloud Integration:**
    -   [ ] User authentication and accounts via **Amazon Cognito**.
    -   [ ] Cloud storage for user grimoires in **Amazon S3**.
-   [ ] **Immersive UI Refactor:**
    -   [ ] Rebuild the main view to look like a physical open book using the `QGraphicsView` framework.
    -   [ ] Implement a page-flipping animation using `QPropertyAnimation`.
-   [ ] **Polished Spell Creation:**
    -   [ ] Add "Wizard 101" style animated text prompts for creating spells.
