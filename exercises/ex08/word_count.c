/*
Program for Exercise 08
Software Systems Spring 2020

Author: Sparsh Bansal

References to resources:
glib - https://developer.ibm.com/tutorials/l-glib/#
gnome file utilities - https://developer.gnome.org/glib/stable/glib-File-Utilities.html
gnome error reporting - https://developer.gnome.org/glib/stable/glib-Error-Reporting.html
gnome string utilities - https://developer.gnome.org/glib/stable/glib-String-Utility-Functions.html
type conversion macros - https://developer.gnome.org/glib/stable/glib-Type-Conversion-Macros.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

/* Splits a text file into words (delimiter = ' ')

Input - gchar * type to hold the file name
Output - ghat ** type holding the words

*/

gchar **splitter(gchar *filename) {

    gchar *contents;
	gsize length;
	GError *err = NULL;
    
    g_file_get_contents (filename, &contents, &length, &err);
    g_assert ((contents == NULL && err != NULL) || (contents != NULL && err == NULL));
    if (err != NULL)
    {
        // Report error to user, and free error
        g_assert (contents == NULL);
        fprintf (stderr, "Unable to read file: %s\n", err->message);
        g_error_free (err);
    }
    else
    {
        // Use file contents
        g_assert (contents != NULL);
    }
    return (g_strsplit(contents, " ", -1));
}

/* Counts the frequency of words in the text
using character array indexing and glib hashmaps 
(referenced above).

Input - gchar** splitted content; GHashTable* empty frequency map
Output - completed GHashTable *freqtable

*/

void counter(gchar ** splitted, GHashTable *freqtable) {
     gchar *key = NULL;
     gchar **key_ptr = splitted;
     
     for (key_ptr; *key_ptr; key_ptr++) {

         key = *key_ptr;

        // Iterates through the hash table to find the key

        // If the key is not found, set its frequency to 1
         if (g_hash_table_lookup(freqtable, g_strdup(key)) == NULL)
         {
            g_hash_table_insert(freqtable, g_strdup(key), GINT_TO_POINTER(1));
         }

        // If the key is found, increment its frequncy by 1
         else
         {
            g_hash_table_insert(freqtable, g_strdup(key), g_hash_table_lookup(freqtable, g_strdup(key)) + 1);
         }
     }
}

/* Iterates through the hashmap and prints each key/value pair

Input - gpointer key, gpointer value, gpointer key-value pair
Output - Stdout print

*/
void iterator_printer(gpointer key, gpointer value, gpointer user_data) {

    printf(user_data, (gchar*)key, GPOINTER_TO_INT(value));

}


int main() {
    gchar **splitted = splitter("2591-0.txt");
    GHashTable *freqtable = g_hash_table_new(g_str_hash, g_str_equal);
    counter(splitted, freqtable);
    g_hash_table_foreach(freqtable, iterator_printer, "%s is %d\n");
    g_hash_table_destroy(freqtable);
    return 0;
}

