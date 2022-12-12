#ifndef SAVE_BMP_H
#define SAVE_BMP_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Structures stockant l'entête d'un fichier BMP https://upload.wikimedia.org/wikipedia/commons/7/75/BMPfileFormat.svg
// L'entête fait 54 octets

// Structure stockant l'entête du fichier BMP
typedef struct {             
  int16_t  type;             // Numéro magique: 0x4d42 (BM en ASCII)
  int32_t  size;             // Taille du fichier en octets
  int32_t  reserved;         // Non utilisé
  int32_t  offset;           // Offset vers les données de l'image en octets depuis le début du fichier (54 octets)
} __attribute__((packed)) bitmap_file_header;   // Packed ajouté pour éviter que le compilateur ne rajoute des octets de padding

// Structure stockant les informations détaillées de l'image
typedef struct {             
  uint32_t  size;  // Taille de l'entête en octets (40 octets)
  int32_t   width_px;         // Largeur de l'image en pixels
  int32_t   height_px;        // Hauteur de l'image en pixels
  uint16_t  planes;           // Nombre de plans de couleur (1)
  uint16_t  bits_per_pixel;   // Nombre de bits par pixel (24)
  uint32_t  compression;      // Type de compression (0)
  uint32_t  image_size_bytes; // Taille de l'image en octets
  int32_t   x_resolution_ppm; // Résolution horizontale en pixels par mètre
  int32_t   y_resolution_ppm; // Résolution verticale en pixels par mètre
  uint32_t  num_colors;       // Nombre de couleurs (0)
  uint32_t  important_colors; // Nombre de couleurs importantes (0)
} __attribute__((packed)) bitmap_info_header;   // Packed ajouté pour éviter que le compilateur ne rajoute des octets de padding



// Structure stockant les couleurs d'un pixel sur 3 octets (Bitmap fonctionne en BGR)
typedef struct {             
    int8_t blue;    // Composante bleue sur un octet
    int8_t green;   // Composante verte sur un octet
    int8_t red;     // Composante rouge sur un octet
} bitmap_rgb; 

// Signature des fonctions
void write_bmp(char * filename, bitmap_file_header * output_file_header, bitmap_info_header*  output_info_header, bitmap_rgb * output_pixels);
void print_file_header(bitmap_file_header *file_header);
void print_info_header(bitmap_info_header *info_header);

#endif /* SAVE_BMP_H */