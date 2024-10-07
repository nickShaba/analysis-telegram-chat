# Telegram Chat History Analyzer

This repository allows you to analyze a Telegram chat history stored in a `result.json` file. Follow the steps below to download and run the scripts.

## Getting Started

1. **Download Chat History**
    - Export your Telegram chat history as `result.json` and place it in the same directory as the scripts.

2. **Open Command Line**
    - Press `Win + R`, type `cmd`, and press Enter to open the console.

3. **Enable Cyrillic Encoding (for proper character display)**
    ```bash
    chcp 65001
    ```

4. **Navigate to the Script Directory**
    ```bash
    cd "path\to\folder\with\scripts"
    ```

5. **Compile the Script**
    - To create an executable, run the following command:
    ```bash
    g++ -o main main.cpp
    ```

6. **Run the Executable**
    - Once compiled, execute the program:
    ```bash
    main
    ```

## Notes
- You can modify `main.cpp` or replace it with other scripts as needed. Just recompile by following step 5.
