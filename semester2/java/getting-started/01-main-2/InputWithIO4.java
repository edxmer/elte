
void main() {
    String age_text = IO.readln("What is your age? ");
    int age = Integer.parseInt(age_text);
    
    var oldAge = age + 1;
    IO.println("You will be " + oldAge + " next year, right?");
}
