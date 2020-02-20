def format_output(func):
    def inner(*args, **kwargs):
        result = func(*args, **kwargs)
        result = "Hello, "+result.upper()
        return result
    return inner

@format_output
def input_string(message):
    return message


print(input_string("good Morning"))
