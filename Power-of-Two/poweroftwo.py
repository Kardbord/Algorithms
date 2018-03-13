def is_power_of_two(num):
    """
    Determines whether or not @num is a power of two
    by taking advantage of the fact that powers of two
    always have exactly one bit flipped.
    """
    if not isinstance(num, int) and not isinstance(num, float) or num == 0:
        return False
    return num & (num - 1) == 0

