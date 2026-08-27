git initimport tkinter as tk
import random

SUBJECTS = {
    "Python": [
        ("Which keyword defines a function?", "def"),
        ("Symbol for a single-line comment?", "#"),
        ("Function to get length of a list?", "len"),
        ("Keyword to exit a loop early?", "break"),
        ("Method to add item to end of list?", "append"),
    ],
    "C": [
        ("Header file for input/output in C?", "stdio.h"),
        ("Keyword to define a constant?", "const"),
        ("Function to print output in C?", "printf"),
        ("Keyword to exit a loop early?", "break"),
        ("Which symbol ends a statement in C?", ";"),
    ],
    "C++": [
        ("Keyword for output stream in C++?", "cout"),
        ("Keyword for input stream in C++?", "cin"),
        ("Keyword to define a class?", "class"),
        ("C++ file extension?", ".cpp"),
        ("Keyword for inheritance in C++?", "public"),
    ],
    "Java": [
        ("Keyword to create an object?", "new"),
        ("Java file extension?", ".java"),
        ("Keyword to define a class?", "class"),
        ("Method where Java program starts?", "main"),
        ("Keyword to inherit a class?", "extends"),
    ],
}


class QuizApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Quiz App")
        self.root.geometry("500x450")
        self.root.resizable(False, False)
        self.root.config(bg="#f0f4f8")

        self.show_home()

    def clear(self):
        for w in self.root.winfo_children():
            w.destroy()

    def show_home(self):
        self.clear()

        # Blue Header
        header = tk.Frame(self.root, bg="#00A2FF", height=70)
        header.pack(fill="x")

        tk.Label(
            header,
            text="QUIZ APP",
            font=("Helvetica", 24, "bold"),
            bg="#00A2FF",
            fg="white"
        ).pack(pady=12)

        tk.Label(
            self.root,
            text="Choose a Subject",
            font=("Helvetica", 15, "bold"),
            bg="#f0f4f8",
            fg="#222"
        ).pack(pady=(20, 20))

        for subject in SUBJECTS:
            tk.Button(
                self.root,
                text=subject,
                font=("Helvetica", 12),
                bg="#4a90d9",
                fg="white",
                relief="flat",
                padx=20,
                pady=6,
                width=14,
                cursor="hand2",
                command=lambda s=subject: self.start_quiz(s)
            ).pack(pady=5)

    def start_quiz(self, subject):
        self.questions = random.sample(
            SUBJECTS[subject],
            len(SUBJECTS[subject])
        )
        self.index = 0
        self.score = 0
        self.subject = subject
        self.show_question()

    def show_question(self):
        self.clear()

        q, _ = self.questions[self.index]

        tk.Label(
            self.root,
            text=self.subject,
            font=("Helvetica", 12, "bold"),
            bg="#f0f4f8",
            fg="#4a90d9"
        ).pack(pady=(20, 5))

        tk.Label(
            self.root,
            text=f"Q{self.index + 1}. {q}",
            wraplength=450,
            font=("Helvetica", 13),
            bg="#f0f4f8",
            fg="#222"
        ).pack(pady=(10, 8))

        self.entry = tk.Entry(
            self.root,
            font=("Helvetica", 12),
            width=25,
            relief="solid",
            bd=1
        )
        self.entry.pack(pady=6)
        self.entry.focus()

        self.entry.bind("<Return>", lambda e: self.check())

        self.feedback = tk.Label(
            self.root,
            text="",
            font=("Helvetica", 11),
            bg="#f0f4f8"
        )
        self.feedback.pack(pady=5)

        self.btn = tk.Button(
            self.root,
            text="Submit",
            font=("Helvetica", 11),
            bg="#4a90d9",
            fg="white",
            relief="flat",
            padx=20,
            pady=6,
            cursor="hand2",
            command=self.check
        )
        self.btn.pack(pady=4)

        tk.Label(
            self.root,
            text=f"{self.index + 1} / {len(self.questions)}",
            font=("Helvetica", 9),
            bg="#f0f4f8",
            fg="#888"
        ).pack(pady=(8, 0))

    def check(self):
        answer = self.entry.get().strip().lower()
        correct = self.questions[self.index][1].lower()

        if answer == correct:
            self.score += 1
            self.feedback.config(
                text="✓ Correct!",
                fg="green"
            )
            
        else:
            self.feedback.config(
                text=f"✗ Wrong! Answer: {correct}",
                fg="red"
            )

        self.entry.config(state="disabled")
        self.btn.config(
            text="Next →",
            command=self.next_q
        )

    def next_q(self):
        self.index += 1

        if self.index < len(self.questions):
            self.show_question()
        else:
            self.show_result()

    def show_result(self):
        self.clear()

        pct = int(
            self.score / len(self.questions) * 100
        )

        if pct == 100:
            grade = "🏆 Perfect!"
        elif pct >= 80:
            grade = "🎉 Great!"
        elif pct >= 60:
            grade = "👍 Good!"
        else:
            grade = "📚 Keep Practicing!"

        tk.Label(
            self.root,
            text="Quiz Complete!",
            font=("Helvetica", 18, "bold"),
            bg="#f0f4f8"
        ).pack(pady=(40, 10))

        tk.Label(
            self.root,
            text=f"{self.score}/{len(self.questions)} ({pct}%)",
            font=("Helvetica", 24, "bold"),
            bg="#d4e3f2",
            fg="#4a90d9",
            padx=20,
            pady=10
        ).pack()

        tk.Label(
            self.root,
            text=grade,
            font=("Helvetica", 14),
            bg="#f0f4f8"
        ).pack(pady=10)

        tk.Button(
            self.root,
            text="Play Again",
            font=("Helvetica", 11),
            bg="#4a90d9",
            fg="white",
            relief="flat",
            padx=16,
            pady=6,
            command=self.show_home
        ).pack(pady=6)

        tk.Button(
            self.root,
            text="Exit",
            font=("Helvetica", 11),
            bg="#888",
            fg="white",
            relief="flat",
            padx=16,
            pady=6,
            command=self.root.destroy
        ).pack(pady=2)


root = tk.Tk()
QuizApp(root)
root.mainloop()