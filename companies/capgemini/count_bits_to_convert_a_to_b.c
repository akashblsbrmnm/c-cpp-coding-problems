/*
 * Counts the number of bit positions that differ between two unsigned integers (Hamming Distance).
 */
unsigned int count_bits_to_flip(unsigned int a, unsigned int b)
{
    unsigned int xor_result = a ^ b;
    unsigned int count = 0;

    while (xor_result != 0)
    {
        xor_result &= (xor_result - 1);  // Remove lowest set bit
        count++;
    }

    return count;
}
