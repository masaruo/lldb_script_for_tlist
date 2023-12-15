import lldb

def print_tlist(debugger, command, result, internal_dict):
    target = debugger.GetSelectedTarget()
    process = target.GetProcess()
    thread = process.GetSelectedThread()
    frame = thread.GetSelectedFrame()
    list_head = frame.FindVariable("head_of_tlist")
    content_type = target.FindFirstType("t_data").GetPointerType()
    current = list_head
    while current.GetValueAsUnsigned() != 0:
        data = current.GetChildMemberWithName('content').Cast(content_type)
        int_data = data.GetChildMemberWithName('_int').GetValueAsSigned()
        str_data = data.GetChildMemberWithName('_str').GetSummary()
        print (f'[:{int_data}:{str_data}]')
        current = current.GetChildMemberWithName('next')



def __lldb_init_module(debugger, internal_dict):
    debugger.HandleCommand("command script add -f print_tlist.print_tlist print_tlist")