### Trabajo Práctico: Implementación de un Gap Buffer en C

**Objetivo:**
Desarrollar una estructura de datos llamada *Gap Buffer* para gestionar texto editable de forma eficiente. Esta estructura es comúnmente utilizada en editores de texto como Emacs para permitir inserciones y eliminaciones rápidas cerca del cursor.

---

### Requisitos mínimos

#### 1. Estructura principal
Crear una estructura en C con el siguiente diseño:

```c
typedef struct {
    char *buffer;     // Array que contiene texto + hueco
    int gap_start;    // Índice donde comienza el gap
    int gap_end;      // Índice donde termina el gap
    int capacity;     // Tamaño total del buffer (incluyendo el gap)
} GapBuffer;
```

#### 2. Funciones a implementar

- `GapBuffer* create_buffer()`  
  Crea un buffer vacío con un gap inicial de tamaño definido (puede ser una constante como `#define GAP_SIZE 8`).

- `GapBuffer* create_buffer_with_text(const char *text, int gap_position)`  
  Crea un buffer que contenga un texto inicial y ubique el gap en una posición elegida.

- `void insert_char(GapBuffer *gb, char c)`  
  Inserta un carácter en la posición actual del cursor (gap_start).

- `void move_cursor_left(GapBuffer *gb)`  
  Mueve el cursor una posición a la izquierda, acercando el inicio del gap al principio del texto.

- `void move_cursor_right(GapBuffer *gb)`  
  Mueve el cursor una posición a la derecha, acercando el gap al final del texto.

- `void print_buffer(GapBuffer *gb)`  
  Imprime el contenido del buffer excluyendo el gap.

- `void free_buffer(GapBuffer *gb)`  
  Libera toda la memoria reservada.

---

### Ejemplo de uso esperado

```c
int main() {
    GapBuffer *gb = create_buffer_with_text("Hola Mundo", 5);
    print_buffer(gb);        // Muestra: Hola Mundo

    insert_char(gb, '!');    // Inserta '!' entre "Hola " y "Mundo"
    print_buffer(gb);        // Muestra: Hola !Mundo

    move_cursor_left(gb);
    insert_char(gb, '*');
    print_buffer(gb);        // Muestra: Hola*!Mundo

    free_buffer(gb);
    return 0;
}
```

---

### Opcionales (Bonus)

- Implementar expansión del gap cuando se llena.
- Permitir eliminación de caracteres.
- Permitir mover el cursor a cualquier posición (función `move_cursor_to(int pos)`).
- Leer texto desde un archivo e inicializar el buffer con ese contenido.

---

### Criterios de evaluación

- Correctitud de la implementación y manejo de memoria.
- Claridad del código y comentarios.
- Modularidad (cada función debe cumplir una única tarea bien definida).
- Código funcional y probado con ejemplos.

---

**Fin de la consigna**