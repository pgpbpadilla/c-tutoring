class StringCompressor {

private:
  string theString;
public:
  StringCompressor() {}
  string compress(string aString, SCStrategy aStrategy) { 
    // keep track of the current symbol
    char currentSymbol;
    int symbolCount = 0;

    string::iterator it = string.iterator;

    currentSymbol = string.charAt(0);
    while (it.next() != null){

      if (aString.charAt(it) != currentSymbol) {
        currentSymbol = aString.charAt(it);
        symbolCount = 1;

        // delete symbolCount chars from the string starting at aString.indexOf(currentSymbol)
        aString.erase(indexOfCurrentSymbol, symbolCount);

        continue;
      }

      symbolCount++;
    }
  }
};
