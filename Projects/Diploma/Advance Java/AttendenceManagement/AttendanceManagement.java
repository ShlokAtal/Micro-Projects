import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

public class AttendanceManagement extends Applet implements ActionListener 
{
    private ArrayList<Student> students;
    private TextField rollField, nameField, enrollmentField;
    private TextArea displayArea;
    private Button addButton, markButton, displayButton;

    public void init() 
    {
        students = new ArrayList<>();
        setLayout(new BorderLayout());
        Panel formPanel = new Panel();
        formPanel.setLayout(new GridLayout(4, 2)); 
        Label rollLabel = new Label("Roll Number:");
        rollField = new TextField(10);
        Label nameLabel = new Label("Student Name:");
        nameField = new TextField(20);
        Label enrollmentLabel = new Label("Enrollment Number:");
        enrollmentField = new TextField(15);

        formPanel.add(rollLabel);
        formPanel.add(rollField);
        formPanel.add(nameLabel);
        formPanel.add(nameField);
        formPanel.add(enrollmentLabel);
        formPanel.add(enrollmentField);

        addButton = new Button("Add Student");
        markButton = new Button("Mark Attendance");
        displayButton = new Button("Display Attendance");
        Panel buttonPanel = new Panel();

        buttonPanel.add(addButton);
        buttonPanel.add(markButton);
        buttonPanel.add(displayButton);

        displayArea = new TextArea(10, 50);
        displayArea.setEditable(false);

        add(formPanel, BorderLayout.NORTH);
        add(buttonPanel, BorderLayout.CENTER);
        add(displayArea, BorderLayout.SOUTH);
        addButton.addActionListener(this);
        markButton.addActionListener(this);
        displayButton.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e) 
    {
        String command = e.getActionCommand();
        String roll = rollField.getText().trim();
        String name = nameField.getText().trim();
        String enrollment = enrollmentField.getText().trim();
        if (command.equals("Add Student")) 
        {
            if (!roll.isEmpty() && !name.isEmpty() && !enrollment.isEmpty()) 
            {
                students.add(new Student(roll, name, enrollment));
                rollField.setText("");
                nameField.setText("");
                enrollmentField.setText("");
                displayArea.append("Added: " + name + " (Roll: " + roll + ", Enrollment: " + enrollment + ")\n");
            }
        }
         else if (command.equals("Mark Attendance")) 
         {
            boolean found = false;
            for (Student student : students) 
            {
                if (student.getRollNumber().equals(roll))
                {
                    student.markPresent();
                    found = true;
                    displayArea.append(name + " marked as present.\n");
                    break;
                }
            }
            if (!found) 
            {
                displayArea.append("Student not found with Roll Number: " + roll + "\n");
            }
        } 
        else if (command.equals("Display Attendance")) 
        {
            displayArea.append("Attendance List:\n");
            for (Student student : students) 
            {
                displayArea.append(student.toString() + "\n");
            }
        }
    }
    class Student 
    {
        private String rollNumber;
        private String name;
        private String enrollmentNumber;
        private boolean isPresent;

        public Student(String rollNumber, String name, String enrollmentNumber) 
        {
            this.rollNumber = rollNumber;
            this.name = name;
            this.enrollmentNumber = enrollmentNumber;
            this.isPresent = false;
        }
        public String getRollNumber() 
        {
            return rollNumber;
        }
        public void markPresent() 
        {
            this.isPresent = true;
        }
        @Override
        public String toString() 
        {
            return "Roll: " + rollNumber + ", Name: " + name + ", Enrollment: " + enrollmentNumber + " - " + (isPresent ? "Present" : "Absent");
        }
    }
}