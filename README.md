# Rsa-C


Rsa codé de manière original en C , avec ce qu'il y'avait dans ces vidéos expliquant comment chiffrer et déchiffrer avec RSA à l'aide d'une feuille et d'un stylo : 

Video 1 théorie : https://www.youtube.com/watch?v=lPNYszuJUGM
![image](https://github.com/CatharsisCoding/Rsa-C/assets/97361977/0bad245f-f127-4ab9-a490-ab022129f4cb)

Video 2 cas pratique: https://www.youtube.com/watch?v=gBHNuFq5PpI

J'ai codé sans l'aide de ChatGPT, à la main (à part pour un rappel sur la fonction mod_pow() voici une video qui explique l'exponentiation modulaire : https://www.youtube.com/watch?v=G2AUL3xxA3U ).

J'ai choisi cette méthode pour faire la puissance et le modulo car on fait moins de calculs. La puissance normale donnait des erreurs, c'est pourquoi j'ai fait des recherches pour voir quelle était la solution et je suis tombé sur cette méthode que j'avais oubliée.


```c
/**
 * Calcule la puissance modulaire rapide
 *
 * Calcule (base^exp) % mod  efficacement grace à l'exponentiation binaire modulaire.
 * Plus rapide que la methode naive car moins de multiplication
 * 
 * @param base La base
 * @param exp L'exposant
 * @param mod Le modulo.
 * @return int Le résultat de (base^exp) % mod.
 */
int mod_pow(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; //On utilise le décalage binaire vers la droite (>> 1) pour diviser exp par 2. 
        base = (base * base) % mod;
    }
    return result;
}
```
