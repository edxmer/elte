import random

# Globális lista a hallgatók tárolására
students = []

# Típusok definiálása (hogy ne "magic stringeket" használjunk)
TYPE_BSC = "BSc"
TYPE_MSC = "MSc"
TYPE_PHD = "PhD"

def init_student(student_type):
    """
    Létrehoz egy hallgatót tuple formátumban random adatokkal.
    
    A tuple szerkezete:
    (id, átlag, életkor, típus, [típus_specifikus_adatok...])
    """
    # Közös adatok generálása
    stud_id = random.randint(1000, 9999)
    gpa = round(random.uniform(2.0, 5.0), 2)  # Átlag
    age = random.randint(18, 30)

    # Típus-specifikus tuple létrehozása
    if student_type == TYPE_BSC:
        # BSc: összesen hallgatott kurzusok száma (int)
        courses_count = random.randint(20, 60)
        return (stud_id, gpa, age, TYPE_BSC, courses_count)
    
    elif student_type == TYPE_MSC:
        # MSc: összesített korrigált kreditindex (double/float)
        cci = round(random.uniform(3.0, 6.0), 2)
        return (stud_id, gpa, age, TYPE_MSC, cci)
    
    elif student_type == TYPE_PHD:
        # PhD: impaktfaktor (float) és Erdős-szám (int)
        impact_factor = round(random.uniform(0.0, 10.0), 2)
        erdos_number = random.randint(1, 10)
        # Itt a C-s struct miatt dönthetünk úgy, hogy ez egy belső tuple, 
        # vagy csak simán hozzáfűzzük a végére. Itt most laposan tároljuk.
        return (stud_id, gpa, age, TYPE_PHD, impact_factor, erdos_number)
    
    else:
        raise ValueError("Ismeretlen hallgatói típus")

def add_student(student_tuple):
    """
    Hozzáadja a kapott student tuple-t a globális listához.
    """
    global students
    students.append(student_tuple)

def filter_student(filter_type):
    """
    Visszaad egy listát, ami csak a paraméterül kapott típusú hallgatókat tartalmazza.
    """
    # List comprehension használata a szűrésre
    # A 3. indexen (negyedik elem) tároljuk a típust a tuple-ben
    return [s for s in students if s[3] == filter_type]

# --- Tesztelés / Főprogram ---
if __name__ == "__main__":
    # 1. Adatok generálása és hozzáadása
    print("--- Hallgatók generálása ---")
    for _ in range(5):
        st = init_student(TYPE_BSC)
        add_student(st)
    
    for _ in range(3):
        st = init_student(TYPE_MSC)
        add_student(st)
        
    for _ in range(2):
        st = init_student(TYPE_PHD)
        add_student(st)

    print(f"Összesen {len(students)} hallgató került a globális listába.")
    print("-" * 30)

    # 2. Szűrés tesztelése
    print(f"--- Csak a {TYPE_PHD} hallgatók listázása ---")
    phd_students = filter_student(TYPE_PHD)
    
    for s in phd_students:
        # A tuple kicsomagolása a kiíráshoz
        s_id, s_gpa, s_age, s_type, s_impact, s_erdos = s
        print(f"ID: {s_id}, Átlag: {s_gpa}, Kor: {s_age}, Típus: {s_type}, "
              f"Impakt: {s_impact}, Erdős-szám: {s_erdos}")

    print("-" * 30)
    
    print(f"--- Csak a {TYPE_BSC} hallgatók listázása ---")
    bsc_students = filter_student(TYPE_BSC)
    for s in bsc_students:
        print(s) # Egyszerű kiíratás
