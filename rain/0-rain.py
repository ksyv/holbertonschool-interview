#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    """
    Calcule la quantité d'eau de pluie retenue entre les murs.

    Args:
        walls: Une liste d'entiers non négatifs représentant la hauteur des murs.

    Returns:
        La quantité totale d'eau de pluie retenue.
    """
    if not walls:
        return 0

    n = len(walls)
    water = 0

    for i in range(n):
        # Trouve la hauteur maximale d'un mur à gauche du mur actuel
        left_max = 0
        for j in range(i):
            left_max = max(left_max, walls[j])

        # Trouve la hauteur maximale d'un mur à droite du mur actuel
        right_max = 0
        for j in range(i + 1, n):
            right_max = max(right_max, walls[j])

        # Calcule le niveau d'eau à la position actuelle
        water_level = min(left_max, right_max)

        # Ajoute l'eau piégée à la position actuelle (si existante)
        if water_level > walls[i]:
            water += water_level - walls[i]

    return water
