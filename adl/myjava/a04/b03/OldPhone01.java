package a04.b03;

public class OldPhone01 {
    public static void main(String[] args) {
        Phone phone =new Phone();
        phone.call();
        phone.send();
        phone.show();
        NewPhone newPhone=new NewPhone();
        newPhone.call();
        newPhone.send();
        newPhone.show();
    }
}
