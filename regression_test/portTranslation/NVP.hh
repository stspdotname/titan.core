// This Test Port skeleton header file was generated by the
// TTCN-3 Compiler of the TTCN-3 Test Executor version CRL 113 200/6 R2A
// for ebensza (ebensza@ebensza) on Fri Aug 11 13:51:04 2017

// Copyright (c) 2000-2018 Ericsson Telecom AB

// You may modify this file. Add your attributes and prototypes of your
// member functions here.

#ifndef NVP_HH
#define NVP_HH

#include "PortVariablesInternal.hh"

namespace PortVariablesInternal {

class NVP : public NVP_BASE {
public:
	NVP(const char *par_port_name = NULL);
	~NVP();

	void set_parameter(const char *parameter_name,
		const char *parameter_value);

private:
	/* void Handle_Fd_Event(int fd, boolean is_readable,
		boolean is_writable, boolean is_error); */
	void Handle_Fd_Event_Error(int fd);
	void Handle_Fd_Event_Writable(int fd);
	void Handle_Fd_Event_Readable(int fd);
	/* void Handle_Timeout(double time_since_last_call); */
protected:
	void user_map(const char *system_port);
	void user_unmap(const char *system_port);

	void user_start();
	void user_stop();

	void outgoing_send(const CHARSTRING& send_par);
};

} /* end of namespace */

#endif
