#include <map>

class DebugLogger
{
public:
    std::map<String, bool> levels;

    DebugLogger(String allLevels[], int numLevels); // Modified constructor

    void writeLog(String str, String levelName)
    {
        Serial.print("[");
        Serial.print(levelName);
        Serial.print("] ");
        Serial.println(str);
    }

    void log(String str, String levelName)
    {
        if (levels[levelName])
        {
            writeLog(str, levelName);
        }

        return;
    }

    void disableLevel(String levelName)
    {
        if (levels[levelName])
        {
            levels[levelName] = false;
        }
    }

    void enableLevel(String levelName)
    {
        if (!levels[levelName])
        {
            levels[levelName] = true;
        }
    }
};

DebugLogger::DebugLogger(String allLevels[], int numLevels)
{
    for (int i = 0; i <= numLevels; i++)
    {
        levels[allLevels[i]] = true;
    }
}