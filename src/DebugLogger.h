class DebugLogger
{
public:
    int numLevels;
    String *levelNames; // Added property for level names

    DebugLogger(int numLevels, String *levelNames); // Modified constructor

    void log(String str, String levelName)
    {
        for (int i = 0; i <= numLevels; i++)
        {
            if (levelNames[i] == levelName)
            {
                Serial.print("[");
                Serial.print(levelName);
                Serial.print("] ");
                Serial.println(str);
                return;
            }
        }

        return;
    }
};

DebugLogger::DebugLogger(int numLevels, String *levelNames)
{
    this->numLevels = numLevels;   // Use "this->" to differentiate between member variable and parameter
    this->levelNames = levelNames; // Assign levelNames array to member variable
}