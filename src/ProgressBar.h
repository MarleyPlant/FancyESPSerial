class ProgressBar {
public:
  int length;
  int progress = 0;

  ProgressBar(int length);

  void start() {
    if(length == 0) {
      return;
    }

    Serial.print("|");
    for (int i = 0; i < length; i++) {
      Serial.print('.');  // print empty 'progress bar' of length
    }
    Serial.println("|");

    Serial.print("|");
  }

  void step() {
    if (progress < length) {
      Serial.print('*');
      progress++;
    } else if (progress == length) {
      Serial.println("|");
      progress++;
    }
  }

  void end() {
    if (progress < length) {
      int numStepsLeft = length - progress;
      for (int i = 0; i <= numStepsLeft; i++) {
        step();
      }
    } else if (progress == length) {
      Serial.println("|");
    }
  }
};

ProgressBar::ProgressBar(int len) {
  length = len;
}