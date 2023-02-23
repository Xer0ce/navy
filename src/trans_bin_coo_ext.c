/*
** EPITECH PROJECT, 2023
** navy
** File description:
** trans_bin_coo
*/

#include "../include/navy_function.h"

char first_bin_one_ext_nbr(int id, char *bin,
char **dictio_letter, char *result)
{
    for (int index_dic = id; index_dic != id + 6; index_dic += 2) {
        if (bin[5] == dictio_letter[index_dic][2])
            return dictio_letter[index_dic - 1][0];
    }
}

char first_bin_one_db_nbr(char *result, char *bin)
{
    char **dictio_letter = create_array("src/txt/dictionary_nbr.txt");

    if (result[0] == '1')
        return first_bin_one_ext_nbr(1, bin, dictio_letter, result);
    if (result[0] == '3')
        return first_bin_one_ext_nbr(5, bin, dictio_letter, result);
    if (result[0] == '5')
        return first_bin_one_ext_nbr(9, bin, dictio_letter, result);
    if (result[0] == '7')
        return first_bin_one_ext_nbr(13, bin, dictio_letter, result);
}

char first_bin_one_nbr(int id, int id_f, char *bin)
{
    char **dictio_letter = create_array("src/txt/dictionary_nbr.txt");
    char result[] = "..";
    int index_result = 0;

    index_result = 0;
    for (int index_dic = id; index_dic != id_f; index_dic += 2) {
        if (bin[4] == dictio_letter[index_dic][1]) {
            result[index_result] = dictio_letter[index_dic - 1][0];
            index_result++;
        }
    }
    return first_bin_one_db_nbr(result, bin);
}

char trans_bin_coo_nbr(char *bin)
{
    char result;

    if (bin[3] == '1')
        result = first_bin_one_nbr(9, 17, bin);
    if (bin[3] == '0')
        result = first_bin_one_nbr(1, 9, bin);
    return result;
}
