/*
** EPITECH PROJECT, 2023
** navy
** File description:
** trans_bin_coo
*/

#include "../include/navy_function.h"

char first_bin_one_ext(int id, char *bin, char **dictio_letter, char *result)
{
    for (int index_dic = id; index_dic != id + 6; index_dic += 2) {
        if (bin[2] == dictio_letter[index_dic][2])
            return dictio_letter[index_dic - 1][0];
    }
}

char first_bin_one_db(char *result, char *bin)
{
    char **dictio_letter = create_array("src/txt/dictionary_letter.txt");

    if (result[0] == 'A')
        return first_bin_one_ext(1, bin, dictio_letter, result);
    if (result[0] == 'C')
        return first_bin_one_ext(5, bin, dictio_letter, result);
    if (result[0] == 'E')
        return first_bin_one_ext(9, bin, dictio_letter, result);
    if (result[0] == 'G')
        return first_bin_one_ext(13, bin, dictio_letter, result);
}

char first_bin_one(int id, int id_f, char *bin)
{
    char **dictio_letter = create_array("src/txt/dictionary_letter.txt");
    char **dictio_nbr = create_array("src/txt/dictionary_nbr.txt");
    char result[] = "..";
    int index_result = 0;

    index_result = 0;
    for (int index_dic = id; index_dic != id_f; index_dic += 2) {
        if (bin[1] == dictio_letter[index_dic][1]) {
            result[index_result] = dictio_letter[index_dic - 1][0];
            index_result++;
        }
    }
    return first_bin_one_db(result, bin);
}

char trans_bin_coo_letter(char *bin)
{
    char result;

    if (bin[0] == '1')
        result = first_bin_one(9, 17, bin);
    if (bin[0] == '0')
        result = first_bin_one(1, 9, bin);
    return result;
}

char *trans_bin_coo(char *bin)
{
    char *result = malloc(sizeof(char) * 3);

    result[0] = trans_bin_coo_letter(bin);
    result[1] = trans_bin_coo_nbr(bin);
    result[2] = '\0';
    return result;
}
