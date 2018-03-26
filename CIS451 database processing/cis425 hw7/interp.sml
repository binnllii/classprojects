Control.Print.printDepth:= 100;

datatype term =
    AST_ID of string
  | AST_NUM of int
  | AST_TRUE
  | AST_FALSE
  | AST_SUCC
  | AST_PRED
  | AST_ISZERO
  | AST_IF of term * term * term
  | AST_FUN of string * term
  | AST_APP of term * term
  | AST_LET of string * term * term ;

datatype result =
    RES_NUM   of int
  | RES_TRUE
  | RES_FALSE
  | RES_SUCC
  | RES_PRED
  | RES_ISZERO
  | RES_FUN   of (string * term) ;

(* Here is a basic environment implementation *)
exception unbound_var;
exception unimplemented;
exception impossible;

datatype env = Env of (string * result) list;

fun empty_env() = Env(nil);
fun extend_env (Env(oldenv), id, value) = Env( (id, value):: oldenv);
fun lookup_env (Env(nil), id) = raise unbound_var
  | lookup_env (Env((id1,value1)::b), id) =
      if (id1 = id)
      then value1
      else lookup_env(Env(b), id) ;

(* Your code goes here. *)
fun interp (t, env) =
	(case t of
    AST_ID (s) => lookup_env(env,s)
  | AST_NUM (n) => RES_NUM n	
  | AST_TRUE => RES_TRUE
  | AST_FALSE => RES_FALSE
  | AST_SUCC => RES_SUCC
  | AST_PRED => RES_PRED
  | AST_ISZERO => RES_ISZERO
	
  | AST_IF (c,t0,t1) =>
    (case interp (c,env) of
         RES_TRUE  => interp (t0,env)
       | RES_FALSE => interp (t1,env)
       | _ => raise impossible)
  | AST_FUN (x,t0) => RES_FUN(x,t0)
	
  | AST_APP (t0,t1) => 
	let val RES_NUM v0 = interp(t1, env)
	in 
	   (case t0 of
		AST_SUCC => RES_NUM(v0 + 1)
	|      AST_PRED =>if (v0 = 0) then RES_NUM 0
		else RES_NUM(v0 - 1)
	|      AST_ISZERO => if (v0 = 0) then RES_TRUE 
		else RES_FALSE
	|	AST_FUN(x, t0) => interp(t0, extend_env(env, x, RES_NUM(v0)))
	| _ => raise impossible)
	end; 

  | AST_LET (x,t0,t1) => 	
	let val v0 = interp(t0, env)
	    val v1 = extend_env(env, x, v0)
      in
	interp(t1,v1)
	end);






#2

Control.Print.printDepth:= 100;

datatype term =
    AST_ID of string
  | AST_NUM of int
  | AST_TRUE
  | AST_FALSE
  | AST_SUCC
  | AST_PRED
  | AST_ISZERO
  | AST_IF of term * term * term
  | AST_FUN of string * term
  | AST_APP of term * term
  | AST_LET of string * term * term ;

datatype result =
    RES_NUM   of int
  | RES_TRUE
  | RES_FALSE
  | RES_SUCC
  | RES_PRED
  | RES_ISZERO
  | RES_FUN   of (string * term) 
  | RES_CLOSURE of (term * env)
	and env = Env of (string * result) list;

(* Here is a basic environment implementation *)
exception unbound_var;
exception unimplemented;
exception impossible;

datatype env = Env of (string * result) list;

fun empty_env() = Env(nil);
fun extend_env (Env(oldenv), id, value) = Env( (id, value):: oldenv);
fun lookup_env (Env(nil), id) = raise unbound_var
  | lookup_env (Env((id1,value1)::b), id) =
      if (id1 = id)
      then value1
      else lookup_env(Env(b), id) ;

(* Your code goes here. *)
fun interp_static (t, env) =
	(case t of
    AST_ID (s) => lookup_env(env,s)
  | AST_NUM (n) => RES_NUM n	
  | AST_TRUE => RES_TRUE
  | AST_FALSE => RES_FALSE
  | AST_SUCC => RES_SUCC
  | AST_PRED => RES_PRED
  | AST_ISZERO => RES_ISZERO
	
  | AST_IF (c,t0,t1) =>
    (case interp (c,env) of
         RES_TRUE  => interp_static (t0,env)
       | RES_FALSE => interp_static (t1,env)
       | _ => raise impossible)
  | AST_FUN (x,t0) => RES_CLOSURE(RES_FUN(x,t0),env)
	
  | AST_APP (t0,t1) => 
	let val RES_NUM v0 = interp_static(t1, env)
	in 
	   (case t0 of
		AST_SUCC => RES_NUM(v0 + 1)
	|      AST_PRED =>if (v0 = 0) then RES_NUM 0 else RES_NUM(v0 - 1)
	|      AST_ISZERO => if (v0 = 0) then RES_TRUE else RES_FALSE
	|	AST_CLOSURE(AST_FUN(x, t0), env1) => interp_static(t0, extend_env(env, x, v0)))
	| _ => raise impossible)
	end; 

  | AST_LET (x,t0,t1) => 	
	let val v0 = interp_static(t0, env)
	    val v1 = extend_env(env, x, v0)
      in
	interp_static(t1,v1)
	end);

	
