"""
Command Line Usage: python3 analysis.py file_name
The output will be printed.
"""
import sys


def remove_leading_zeros(address):
    for i in range(len(address)):
        if address[i] != "0":
            return address[i:]
    
    return 0


def main():
    filename = sys.argv[1]
    num_access = {
        "I": 0,
        "L": 0,
        "S": 0,
        "M": 0
    }
    ins_address_count = {}
    data_address_count = {}

    with open(filename, "r") as f:
        traces = f.readlines()

    for trace in traces:
        whole = trace.split()
        access = whole[0]
        address = whole[1].split(",")[0]
        page_number = "0x" + remove_leading_zeros(address[:len(address) - 3]) + "000"

        if access in num_access:
            num_access[access] += 1

        if access == "I":
            if page_number not in ins_address_count:
                ins_address_count[page_number] = 0
            ins_address_count[page_number] += 1
        elif access in ["L", "S", "M"]:
            if page_number not in data_address_count:
                data_address_count[page_number] = 0
            data_address_count[page_number] += 1

    print(filename)
    print()

    print("Counts:")
    print("  Instructions ", num_access["I"])
    print("  Loads        ", num_access["L"])
    print("  Stores       ", num_access["S"])
    print("  Modifies     ", num_access["M"])
    print()

    print("The number of instruction pages: {}".format(len(ins_address_count)))
    print("The number of data pages: {}".format(len(data_address_count)))
    print()

    print("Instructions:")
    for ins_address in ins_address_count:
        print("{},{}".format(ins_address, ins_address_count[ins_address]))

    print("Data:")
    for data_address in data_address_count:
        print("{},{}".format(data_address, data_address_count[data_address]))
    print()


if __name__ == "__main__":
    main()
