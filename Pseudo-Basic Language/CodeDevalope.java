import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CodeDevalope {

  private static Map<String, Object> variableMap;

  private static Object getVariableValue(String variable) {
    // return variableMap.getOrDefault(variable, 0);
    Object value = variableMap.get(variable);
    if (value instanceof Integer) {
      return (int) value;
    }
    return value;
  }

  private static void variableDeclarator(String name, String Value) {

    // check if Value is int else String
    // String regexIntMatcher = "-?\\d+"; // not needed

    try {
      // Value.matches(regexIntMatcher);
      int numValue = Integer.parseInt(Value);

      // Treat as Int
      // System.out.println("Int: " + numValue + " is " + Value.getClass());
      variableMap.put(name, numValue);

    } catch (NumberFormatException E) {

      // Treat as string
      // System.out.println("String: " + Value + " is " + Value.getClass());
      variableMap.put(name, Value);

    }
  }

  private static void codeMatcher(String line) {
    // String pseudoCode = "LET variable = hello";

    // Define the regular expression pattern for the basic-style pseudo-code
    Pattern pattern = Pattern.compile("(?i)\\b(LET)\\s+([a-zA-Z0-9_]*)\\s*=\\s*([a-zA-Z0-9_]*)\\b|"
        + "(IF\\s+([a-zA-Z][a-zA-Z0-9_]*)\\s+THEN\\s+([a-zA-Z][a-zA-Z0-9_]*))|"
        + "(WHILE\\s+([a-zA-Z][a-zA-Z0-9_]*)\\s+DO\\s+([a-zA-Z][a-zA-Z0-9_]*))|"
        + "(ENDIF)|"
        + "(LOOP)");

    // (?i)(Let\\s+([a-zA-Z0-9_]*)+\\s+=\\s+([a-zA-Z0-9_]*))|

    Matcher matcher = pattern.matcher(line);

    // Check if the pseudo-code matches the pattern
    if (matcher.matches()) {
      // Check which pattern is matched and extract variables accordingly
      String letVariable = matcher.group(2);
      String letValue = matcher.group(3);
      String ifCondition = matcher.group(5);
      String ifAction = matcher.group(6);
      String whileCondition = matcher.group(8);
      String whileAction = matcher.group(9);
      String endif = matcher.group(10);
      String loop = matcher.group(11);

      if (letVariable != null) {
        System.out.println("LET Statement");
        System.out.println("Variable: " + letVariable);
        System.out.println("Value: " + letValue);

        // initialize variable
        variableDeclarator(letVariable, letValue);

      } else if (ifCondition != null) {
        System.out.println("IF Statement");
        System.out.println("Condition: " + ifCondition);
        System.out.println("Action: " + ifAction);
      } else if (whileCondition != null) {
        System.out.println("WHILE Statement");
        System.out.println("Condition: " + whileCondition);
        System.out.println("Action: " + whileAction);
      } else if (endif != null) {
        System.out.println("ENDIF Statement");
      } else if (loop != null) {
        System.out.println("LOOP Statement");
      }
    } else {
      System.out.println("Invalid pseudo-code.");
    }
  }

  // Debug method to print out all variables in system
  private static void printMemory() {
    System.out.println("\n ___PRINTING ALL MEMORY___");
    for (Map.Entry<String, Object> entry : variableMap.entrySet()) {
      String key = entry.getKey();
      Object value = entry.getValue();

      if (value instanceof Integer) {
        System.out.println("int " + key + " : " + value);
      } else {
        System.out.println("String " + key + " : " + value);
      }
    }
    System.out.println("__________________________\n");
  }

  public static void main(String[] args) {

    variableMap = new HashMap<>(); // hashmap to store variables

    String filePath = "code.txt";
    try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
      String line;
      while ((line = reader.readLine()) != null) {
        System.out.println(line);
        codeMatcher(line);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }

    printMemory();
  }
}