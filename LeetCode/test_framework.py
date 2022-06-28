def test(inputs, truth, func, verbose = True):
    for i in range(len(inputs)):
        output = func(inputs[i])
        if truth[i] != output:
            if verbose:
                print(f"Test {i + 1}:\nExp:\t{str(truth[i])}\nGot:\t{str(output)}")
        else:
            if verbose:
                print(f"Test {i + 1} is correct")